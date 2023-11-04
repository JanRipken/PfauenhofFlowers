#include "../header/cli.hpp"
#include "../header/customer.hpp"
#include "../header/helper.hpp"
#include "../header/postgres.hpp"

#include <cstdlib>
#include <iostream>
void cli::neuerKunde(postgress &myDatabase) {
  std::cout << "==========================================================="
            << std::endl;
  std::cout << "======================== Neuer Kunde ======================"
            << std::endl;
  std::cout << "==========================================================="
            << std::endl;

  std::cout << "Kunden ID: ";
  int kundenid;
  std::cin >> kundenid;

  std::cout << "Kunden Vorname: ";
  std::string vorname;
  std::cin >> vorname;

  std::cout << "Kunden Nachname: ";
  std::string nachname;
  std::cin >> nachname;

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

  Customer customer(kundenid, vorname, nachname, straße, hausnummer,
                    postleitzahl, wohnort);
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

    GrabTyp grabTyp = helper::stringToGrabTyp(grabTypStr);

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

      Jahreszeit jahreszeit = helper::stringToJahreszeit(stringJahreszeit);

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

  // todo: anpassen
  std::string sql = myDatabase.CustomerSQLString(customer);

  std::unique_ptr<pqxx::connection> ptr_dbConnect = myDatabase.connectionOpen();
  myDatabase.getData(ptr_dbConnect, sql);
  myDatabase.connectionClose(ptr_dbConnect);

  std::cout
      << "==================== Kunde Erfolgreich Angelegt ================="
      << std::endl;
  std::cout << "Drücke Enter, um fortzufahren... ";
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
void cli::stammdatenAnpassen() {
  system("clear");
  std::cout << "==========================================================="
            << std::endl;
  std::cout << "==================== Stammdaten Anpassen =================="
            << std::endl;
  std::cout << "==========================================================="
            << std::endl;

  std::cout << "===================== Kunden suchen: 1 ===================="
            << std::endl;
  std::cout << "===================== Stammdaten eines Kunden ändern: 2 ==="
            << std::endl;
  std::cout << "===================== Stammdaten eines Kunden löschen: 3 =="
            << std::endl;
  std::cout << "===================== Kunden löschen: 4 ==================="
            << std::endl;
  std::cout << "===================== Zurück zum Hauptmenü: 5 ============="
            << std::endl;
  std::cout << "==========================================================="
            << std::endl;
  int auswahl;
  std::cin >> auswahl;
  switch (auswahl) {
  case 1:
    break;
  case 2:
    break;
  case 3:
    break;
  case 4:
    break;
  case 5:
    MainMenu();
    break;
  }
}

void cli::neueRechnung() {
  system("clear");
  std::cout << "==========================================================="
            << std::endl;
  std::cout << "======================== Rechnungen ======================="
            << std::endl;
  std::cout << "==========================================================="
            << std::endl;

  std::cout << "======================== Neue Rechnungen: 1 ==============="
            << std::endl;
  std::cout << "======================== Zurück zum Hauptmenü: 5 =========="
            << std::endl;
  std::cout << "==========================================================="
            << std::endl;
  int auswahl;
  std::cin >> auswahl;
  switch (auswahl) {
  case 1:
    break;
  case 2:
    break;
  case 3:
    break;
  case 4:
    break;
  case 5:
    MainMenu();
    break;
  }
}

void cli::abbrechen() {
  std::cout << "==========================================================="
            << std::endl;
  std::cout << "Das Programm wird beendet. Auf Wiedersehen!" << std::endl;
  std::cout << "==========================================================="
            << std::endl;
  exit(0);
}

void cli::MainMenu() {
  system("clear");

  postgress myDatabase;

  std::cout << "==========================================================="
            << std::endl;
  std::cout << "======================== Hauptmenü ========================"
            << std::endl;
  std::cout << "==========================================================="
            << std::endl;
  std::cout << "===================== Neuer Kunde: 1 ======================"
            << std::endl;
  std::cout << "===================== Stammdaten ändern: 2 ================"
            << std::endl;
  std::cout << "===================== Rechnungen: 3 ======================="
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
    stammdatenAnpassen();
    break;

  case 3:
    neueRechnung();
    break;

  case 4:
    abbrechen();
    break;
  }
}
