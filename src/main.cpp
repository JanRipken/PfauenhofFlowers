#include "../header/customer.hpp"
#include "../header/postgres.hpp"
#include "cli.cpp"
#include <iostream>

int main(int argc, char *argv[]) {
  postgress myDatabase;

  // std::unique_ptr<pqxx::connection> ptr_dbConnect =
  //  myDatabase.connectionOpen();
  //  std::string sql = "SELECT * FROM COMPANY where ID = 4";
  //  myDatabase.getData(ptr_dbConnect, sql);
  //  myDatabase.connectionClose(ptr_dbConnect);
  while (true) {
    mainMENU();
  }
  return 0;
}
