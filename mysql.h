#include <mysql/mysql.h>
#include <iostream>
#include <string>
#include <vector>

class Conn
{
    public:
        Conn(const char *ip, const char *dname, const char *uname, const char *pwd, short port);
        Conn(const Conn &conn);
        Conn(Conn &&conn);
        Conn& operator=(const Conn&);
        Conn& operator=(Conn &&conn);


        bool query(const char *sql);
        bool insert(const char *sql);
        std::vector<std::string> getRow();
        const char *strErr() const { return mysql_error(mysql); };

        ~Conn()
        {
            free();
        }
        bool connected() const { return connected_; }

    private:
        void free();

    private:
        const char *ip_;
        const char *dname_;
        const char *uname_;
        const char *pwd_;
        short port_;

        MYSQL *mysql = nullptr;
        bool connected_ = false;
        MYSQL_RES *res = nullptr;
        MYSQL_ROW row;
};

Conn::Conn(const char *ip, const char *dname, const char *uname, const char *pwd, short port)
{
    ip_ = ip;
    uname_ = uname;
    pwd_ = pwd;
    dname_ = dname;
    port_ = port;
    mysql = mysql_init(nullptr);

    if (mysql_real_connect(mysql, ip, uname, pwd, dname, port, 0, NULL))
    {
        connected_ = true;
    }
}

inline Conn::Conn(const Conn &conn) : Conn(conn.ip_, conn.dname_, conn.uname_, conn.pwd_, conn.port_)
{
}

inline Conn::Conn(Conn &&conn)
{
    this->res = conn.res;
    this->mysql = conn.mysql;
    this->row = conn.row;
    this->connected_ = conn.connected_;

    conn.res = nullptr;
    conn.mysql = nullptr;
    conn.row = nullptr;
}

inline Conn &Conn::operator=(const Conn &conn)
{
    if (this == &conn)
    {
        return *this;
    }

    free();
    mysql = mysql_init(nullptr);

    if (mysql_real_connect(mysql, conn.ip_, conn.uname_, conn.pwd_, conn.dname_, conn.port_, nullptr, 0))
    {
        connected_ = true;
    }
    return *this;
}

inline Conn &Conn::operator=(Conn &&conn)
{
    if (&conn == this)
    {
        return *this;
    }
    free();
    this->res = conn.res;
    this->mysql = conn.mysql;
    this->row = conn.row;
    this->connected_ = conn.connected_;

    conn.res = nullptr;
    conn.mysql = nullptr;
    conn.row = nullptr;
    return *this;
}

inline bool Conn::query(const char *sql)
{

    if (!mysql_query(mysql, sql))
    {
        if (res)
        {
            mysql_free_result(res);
            res = nullptr;
        }
        res = mysql_use_result(mysql);
        return true;
    }

    return false;
}

inline bool Conn::insert(const char *sql)
{
    return !mysql_query(mysql, sql);
}

inline std::vector<std::string> Conn::getRow()
{
    std::vector<std::string> ret;
    row = mysql_fetch_row(res);
    auto n = mysql_num_fields(res);
    if (row)
    {
        for (uint32_t i = 0; i < n; i++)
            ret.push_back(row[i]);
    }
    else
    {
        mysql_free_result(res);
        res = nullptr;
    }
    return ret;
}

inline void Conn::free()
{

    if (mysql)
    {
        mysql_close(mysql);
        mysql = nullptr;
    }
    if (res)
    {
        mysql_free_result(res);
        res = nullptr;
    }
    if (row)
    {
        row = nullptr;
    }
}
