#include "../header/helper.hpp"

GrabTyp helper::stringToGrabTyp(const std::string &str) {
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

Jahreszeit helper::stringToJahreszeit(const std::string &str) {
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
