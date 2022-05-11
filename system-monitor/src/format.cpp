#include <string>

#include "format.h"

using std::string;

string Format::ElapsedTime(long seconds) {

  long hours = seconds / 3600;
  seconds %= 3600;
  long minutes = seconds / 60;
  seconds %= 60;

  if (seconds < 10)
    return std::to_string(hours) + ":" + std::to_string(minutes) + ":0" +
           std::to_string(seconds);

  return std::to_string(hours) + ":" + std::to_string(minutes) + ":" +
         std::to_string(seconds);
}