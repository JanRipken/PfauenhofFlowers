#ifndef GRAVE_HPP
#define GRAVE_HPP

#include "./plant.hpp"
#include <cmath>
#include <string>
#include <vector>

enum GrabTyp {

  Einzelgrab,
  Doppelgrab,
  Familiengrab,
  Urnengrab,
  Gemeinschaftsgrab,
};

class Grave {
public:
  Grave(double &Größe, const std::string &Ort, GrabTyp &grabTyp,
        std::vector<Plant> &plants)
      : Größe(Größe), Ort(Ort), grabTyp(grabTyp), plants(plants) {}

private:
  double Größe;
  std::string Ort;
  GrabTyp grabTyp;
  std::vector<Plant> plants;
};

#endif
