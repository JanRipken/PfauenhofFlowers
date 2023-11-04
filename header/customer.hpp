#ifndef CUSTOMER_HPP
#define CUSTOMER_HPP
#include "./grave.hpp"
#include "order.hpp"
#include <string>
#include <vector>
class Customer {
public:
  Customer(const int KundenID, const std::string &Vorname,
           const std::string &Nachname, const std::string &Straße,
           const std::string &Hausnummer, const std::string &Postleitzahl,
           std::string &Wohnort)
      : KundenID(KundenID), Vorname(Vorname), Nachname(Nachname),
        Straße(Straße), Hausnummer(Hausnummer), Postleitzahl(Postleitzahl),
        Wohnort(Wohnort) {}

  void addGrave(Grave grave) { graves.push_back(grave); }

  int &getKundenID() { return KundenID; }
  std::string &getVorname() { return Vorname; }
  std::string &getNachname() { return Nachname; }
  std::string &getStrasse() { return Straße; }
  std::string &getHausnummer() { return Hausnummer; }
  std::string &getPostleitzahl() { return Postleitzahl; }
  std::string &getWohnort() { return Wohnort; }
  float &getRechnungsnummer() { return Rechnungsnummer; }
  std::vector<Grave> &getGrave() { return graves; }
  std::vector<Order> &getOrder() { return orders; }

private:
  int KundenID;
  std::string Vorname;
  std::string Nachname;
  std::string Straße;
  std::string Hausnummer;
  std::string Postleitzahl;
  std::string Wohnort;
  float Rechnungsnummer;
  std::vector<Grave> graves;
  std::vector<Order> orders;
};

#endif
