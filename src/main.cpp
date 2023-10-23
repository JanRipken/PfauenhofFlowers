#include <iostream>
#include <memory>
#include <pqxx/pqxx>

std::unique_ptr<pqxx::connection> dbconnect() {
  try {
    auto connectionPtr = std::make_unique<pqxx::connection>(
        "dbname = postgres user = postgres password = postgres \
      hostaddr = 127.0.0.1 port = 5432");

    if (connectionPtr->is_open()) {
      std::cout << "Opened database successfully: " << connectionPtr->dbname()
                << std::endl;
    } else {
      std::cout << "Can't open database" << std::endl;
    }

    return connectionPtr;
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
    return nullptr;
  }
}

void createTable(std::unique_ptr<pqxx::connection> &conn) {

  pqxx::work W(*conn);
  std::string sql = "CREATE TABLE COMPANY("
                    "ID INT PRIMARY KEY     NOT NULL,"
                    "NAME           TEXT    NOT NULL,"
                    "AGE            INT     NOT NULL,"
                    "ADDRESS        CHAR(50),"
                    "SALARY         REAL );";

  W.exec(sql);
  W.commit();
}

void insertData(std::unique_ptr<pqxx::connection> &conn) {

  pqxx::work W(*conn);
  std::string sqlInsert = "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) "
                          "VALUES (1, 'Paul', 32, 'California', 20000.00 ); "
                          "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) "
                          "VALUES (2, 'Allen', 25, 'Texas', 15000.00 ); "
                          "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY)"
                          "VALUES (3, 'Teddy', 23, 'Norway', 20000.00 );"
                          "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY)"
                          "VALUES (4, 'Mark', 25, 'Rich-Mond ', 65000.00 );";

  W.exec(sqlInsert);
  W.commit();
}

void selectData(std::unique_ptr<pqxx::connection> &conn) {

  std::string sqlSelect = "SELECT * from COMPANY";

  pqxx::nontransaction N(*conn);

  pqxx::result R(N.exec(sqlSelect));

  for (pqxx::result::const_iterator c = R.begin(); c != R.end(); ++c) {
    std::cout << "ID = " << c[0].as<int>() << std::endl;
    std::cout << "Name = " << c[1].as<std::string>() << std::endl;
    std::cout << "Age = " << c[2].as<int>() << std::endl;
    std::cout << "Address = " << c[3].as<std::string>() << std::endl;
    std::cout << "Salary = " << c[4].as<float>() << std::endl;
  }
}

void deleteData(std::unique_ptr<pqxx::connection> &conn) {
  /* Create a transactional object. */
  pqxx::work W(*conn);
  /* Create  SQL DELETE statement */
  std::string sql = "DELETE from COMPANY where ID = 2";
  /* Execute SQL query */
  W.exec(sql);
  W.commit();
  std::cout << "Records deleted successfully" << std::endl;
}

void updateData(std::unique_ptr<pqxx::connection> &conn) {

  /* Create a transactional object. */
  pqxx::work W(*conn);
  /* Create  SQL UPDATE statement */
  std::string sql = "UPDATE COMPANY set SALARY = 25000.00 where ID=1";
  /* Execute SQL query */
  W.exec(sql);
  W.commit();
  std::cout << "Records updated successfully" << std::endl;
}

int main(int argc, char *argv[]) {
  try {
    auto connectionPtr = dbconnect();
    selectData(connectionPtr);
    deleteData(connectionPtr);
    selectData(connectionPtr);
  } catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }
}
