#include <string>

#include "format.h"

using std::string;

string Format::ElapsedTime(long seconds) {

  long minutes = seconds / 60;
  seconds = seconds % 60;
  long hours = minutes / 60;
  minutes = minutes % 60;

  return std::to_string(hours) + ":" + std::to_string(minutes) + ":" +
         std::to_string(seconds);
}