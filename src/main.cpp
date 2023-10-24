#include "../header/customer.hpp"
#include "../header/postgres.hpp"
#include "cli.cpp"
#include <iostream>

int main(int argc, char *argv[]) {

  postgress myDatabase;

  while (true) {
    mainMENU(myDatabase);
  }
  return 0;
}
