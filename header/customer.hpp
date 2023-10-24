#ifndef CUSTOMER_HPP
#define CUSTOMER_HPP
#include "./grave.hpp"
#include "order.hpp"
#include <string>
#include <vector>
class Customer {
public:
  Customer(const std::string &Name, const std::string &Straße,
           const std::string &Hausnummer, const std::string &Postleitzahl,
           std::string &Wohnort)
      : Name(Name), Straße(Straße), Hausnummer(Hausnummer),
        Postleitzahl(Postleitzahl), Wohnort(Wohnort) {}

private:
  std::string Name;
  std::string Straße;
  std::string Hausnummer;
  std::string Postleitzahl;
  std::string Wohnort;
  float Rechnungsnummer;
  std::vector<Grave> graves;
  std::vector<Order> orders;
};

#endif
