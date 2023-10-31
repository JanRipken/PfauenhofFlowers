#ifndef CLI_HPP
#define CLI_HPP

#include "postgres.hpp"
class cli {
public:
  void MainMenu(postgress &myDatabase);

private:
  void neuerKunde(postgress &myDatabase);
  void stammdatenAnpassen();
  void neueRechnung();
  void abbrechen();
};
#endif // DEBUG
