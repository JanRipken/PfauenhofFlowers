#ifndef DATABASE_HPP
#define DATABASE_HPP

#include "customer.hpp"
#include <algorithm>
#include <pqxx/pqxx>
#include <string>

class postgress {
public:
  std::unique_ptr<pqxx::connection> connectionOpen();

  void connectionClose(std::unique_ptr<pqxx::connection> &conn);

  void dbExecCommand(std::unique_ptr<pqxx::connection> &conn,
                     std::string string_sql);

  void getData(std::unique_ptr<pqxx::connection> &conn, std::string string_sql);

  std::string CustomerSQLString(Customer &customer);

private:
  std::string dbName = "pfauenhof";
  std::string dbBenutzer = "postgres";
  std::string dbPassword = "postgres";
  std::string dbHostAddresse = "127.0.0.1";
  std::string dbPort = "5432";
};

#endif // !DATABASE_HPP
