#ifndef PLANT_HPP
#define PLANT_HPP

#include <string>
#include <vector>

enum Jahreszeit {
  ganzjährig,
  Frühling,
  Sommer,
  Herbst,
  Winter,

};

class Plant {
public:
  Plant(const std::string &Pflanzenart, Jahreszeit jahreszeit,
        const std::string &Dünger, const std::string &Erde)
      : Pflanzenart(Pflanzenart), jahreszeit(jahreszeit), Dünger(Dünger),
        Erde(Erde) {}

private:
  std::string Pflanzenart;
  Jahreszeit jahreszeit;
  std::string Dünger;
  std::string Erde;
};

#endif // !PLANT_HPP
