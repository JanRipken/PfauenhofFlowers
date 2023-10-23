#include "../header/postgres.hpp"
#include <iostream>

std::unique_ptr<pqxx::connection> postgress::connectionOpen() {
  try {
    std::string connection_string =
        "dbname = " + dbName + " user = " + dbBenutzer +
        " password = " + dbPassword + " hostaddr = " + dbHostAddresse +
        " port = " + dbPort;

    auto connectionPtr = std::make_unique<pqxx::connection>(connection_string);

    if (connectionPtr->is_open()) {
      std::cout << "Opened database successfully: " << connectionPtr->dbname()
                << std::endl;
    } else {
      std::cout << "Can't open database" << std::endl;
      return nullptr;
    }

    return connectionPtr;
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
    return nullptr;
  }
}

void postgress::connectionClose(std::unique_ptr<pqxx::connection> &conn) {
  if (conn) {
    conn->disconnect();
    std::cout << "Closed database connection" << std::endl;
  }
}

void postgress::dbExecCommand(std::unique_ptr<pqxx::connection> &conn,
                              std::string string_sql) {
  pqxx::work W(*conn);
  W.exec(string_sql);
  W.commit();
}

void postgress::getData(std::unique_ptr<pqxx::connection> &conn,
                        std::string string_sql) {
  pqxx::nontransaction N(*conn);
  pqxx::result R(N.exec(string_sql));

  for (pqxx::result::const_iterator row = R.begin(); row != R.end(); ++row) {
    for (int col = 0; col < row.size(); ++col) {
      std::cout << row[col].name() << " = " << row[col].c_str() << std::endl;
    }
    std::cout << std::endl;
  }
}
