#include "../header/customer.hpp"
#include "../header/postgres.hpp"

#include <iostream>
#include <string>

void neuerKunde() {
  std::cout << "==========================================================="
            << std::endl;
  std::cout << "======================== Neuer Kunde ======================"
            << std::endl;
  std::cout << "==========================================================="
            << std::endl;
  std::cout << "Kunden Name: ";
  std::string name;
  std::cin >> name;

  std::cout << "Kunden Straße: ";
  std::string straße;
  std::cin >> straße;

  std::cout << "Kunden Hausnummer: ";
  std::string hausnummer;
  std::cin >> hausnummer;

  std::cout << "Kunden Postleitzahl: ";
  std::string postleitzahl;
  std::cin >> postleitzahl;

  std::cout << "Kunden Wohnort: ";
  std::string wohnort;
  std::cin >> wohnort;

  exit(0);
}

void neueBestellung(Customer customer, Order order) {}

void stammdatenÄndern(Customer customer) {}

void verlassen() {
  std::cout << "==========================================================="
            << std::endl;

  std::cout << "Das Programm wird beendet. Auf Wiedersehen!" << std::endl;
  std::cout << "==========================================================="
            << std::endl;

  exit(0);
}

void mainMENU() {
  std::cout << "==========================================================="
            << std::endl;
  std::cout << "======================== Hauptmenü ========================"
            << std::endl;
  std::cout << "==========================================================="
            << std::endl;
  std::cout << "===================== Neuer Kunde: 1 ======================"
            << std::endl;
  std::cout << "===================== Neue Bestellung: 2 =================="
            << std::endl;
  std::cout << "===================== Stammdaten ändern: 3 ================"
            << std::endl;
  std::cout << "===================== Verlassen: 4 ========================"
            << std::endl;
  std::cout << "==========================================================="
            << std::endl;

  int eingabe;
  std::cin >> eingabe;
  std::cout << "==========================================================="
            << std::endl;
  switch (eingabe) {

  case 1:
    neuerKunde();
    break;

  case 2:
    break;

  case 3:
    break;

  case 4:
    verlassen();
    break;
  }
}
