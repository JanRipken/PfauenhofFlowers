#include "../header/customer.hpp"
#include "../header/postgres.hpp"

#include <iostream>
#include <string>

GrabTyp stringToGrabTyp(const std::string &str) {
  if (str == "Einzelgrab") {
    return Einzelgrab;
  } else if (str == "Doppelgrab") {
    return Doppelgrab;
  } else if (str == "Familiengrab") {
    return Familiengrab;
  } else if (str == "Urnengrab") {
    return Urnengrab;
  } else if (str == "Gemeinschaftsgrab") {
    return Gemeinschaftsgrab;
  } else {
    return Einzelgrab;
  }
}

Jahreszeit stringToJahreszeit(const std::string &str) {
  if (str == "Ganzjährig") {
    return ganzjährig;
  } else if (str == "Frühling") {
    return Frühling;
  } else if (str == "Sommer") {
    return Sommer;
  } else if (str == "Herbst") {
    return Herbst;
  } else if (str == "Winter") {
    return Winter;
  } else {
    return ganzjährig;
  }
}

void neuerKunde(postgress &myDatabase) {
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

  Customer customer(name, straße, hausnummer, postleitzahl, wohnort);
  std::cout << "Wollen sie direkt ein Grab mit anlegen (y/n): ";
  std::string grabanlegen;
  std::cin >> grabanlegen;
  std::cout << "==========================================================="
            << std::endl;

  if (grabanlegen == "y") {
    std::cout << "Grab Größe: ";
    double groesse;
    std::cin >> groesse;

    std::cout << "Grab Ort: ";
    std::string grabort;
    std::cin >> grabort;

    std::string grabTypStr;
    std::cout << "Geben Sie den Grab Typ ein (Einzelgrab, Doppelgrab, "
                 "Familiengrab, Urnengrab, Gemeinschaftsgrab): ";
    std::cin >> grabTypStr;

    GrabTyp grabTyp = stringToGrabTyp(grabTypStr);

    std::cout << "Anzahl der Pflanzen im Grab: ";
    int anzahlPflanzen;
    std::cin >> anzahlPflanzen;

    std::vector<Plant> pflanzen;
    for (int i = 0; i < anzahlPflanzen; i++) {
      std::cout << "Pflanze " << i + 1 << " Art: ";
      std::string art;
      std::cin >> art;

      std::cout
          << "Pflanze " << i + 1
          << " Jahreszeit(Ganzjähirg, Frühling, Sommer, Herbst, Winter): ";
      std::string stringJahreszeit;
      std::cin >> stringJahreszeit;

      Jahreszeit jahreszeit = stringToJahreszeit(stringJahreszeit);

      std::cout << "Pflanze " << i + 1 << " Dünger: ";
      std::string duenger;
      std::cin >> duenger;

      std::cout << "Pflanze " << i + 1 << " Erde: ";
      std::string erde;
      std::cin >> erde;

      Plant plant(art, jahreszeit, duenger, erde);
      pflanzen.push_back(plant);
      std::cout << "==========================================================="
                << std::endl;
    };

    Grave grave(groesse, grabort, grabTyp, pflanzen);
    customer.addGrave(grave);
  }

  std::string sql = "INSERT INTO NEUERKUNDE (name, straße, "
                    "hausnummer, postleitzahl, wohnort) VALUES ('" +
                    name + "', '" + straße + "', '" + hausnummer + "', '" +
                    postleitzahl + "', '" + wohnort + "');";

  std::unique_ptr<pqxx::connection> ptr_dbConnect = myDatabase.connectionOpen();
  myDatabase.getData(ptr_dbConnect, sql);
  myDatabase.connectionClose(ptr_dbConnect);
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

void mainMENU(postgress &myDatabase) {
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
    neuerKunde(myDatabase);
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
