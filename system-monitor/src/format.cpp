#include <string>

#include "format.h"

using std::string;

string Format::ElapsedTime(long seconds) {

  long minutes = seconds / 60;
  seconds %= 60;
  long hours = minutes / 60;
  minutes %= 60;
  string twoDigitSeconds = std::to_string(seconds).insert(
      0, 2 - std::to_string(seconds).length(), '0');
  string twoDigitMinutes = std::to_string(minutes).insert(
      0, 2 - std::to_string(minutes).length(), '0');
  string minTwoDigitHours =
      std::to_string(hours).insert(0, 2 - std::to_string(hours).length(), '0');
  return minTwoDigitHours + ":" + twoDigitMinutes + ":" + twoDigitSeconds;
}