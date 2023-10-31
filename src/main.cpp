#include "../header/cli.hpp"
#include "../header/customer.hpp"
#include "../header/postgres.hpp"
#include <iostream>

int main(int argc, char *argv[]) {

  cli mainCLI;

  while (true) {
    mainCLI.MainMenu();
  }
  return 0;
}
