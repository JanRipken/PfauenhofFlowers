
// helper.hpp

#ifndef HELPER_HPP
#define HELPER_HPP

#include "./grave.hpp"
#include <string>
class helper {
public:
  static GrabTyp stringToGrabTyp(const std::string &grabTypStr);
  static Jahreszeit stringToJahreszeit(const std::string &str);
};

#endif // !HELPER_HPP
