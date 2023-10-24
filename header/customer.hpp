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

  Customer(const std::string &Name, const std::string &Straße,
           const std::string &Hausnummer, const std::string &Postleitzahl,
           const std::string &Wohnort, const Grave &grab)
      : Name(Name), Straße(Straße), Hausnummer(Hausnummer),
        Postleitzahl(Postleitzahl), Wohnort(Wohnort) {
    graves.push_back(grab);
  }

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
