#include <cassert>

class Date {
public:
  Date(int day, int month, int year);
  int Day() { return day; }
  void Day(int d) {
    if (d >= 1 && d <= 31)
      day = d;
  }
  int Month() { return month; }
  void Month(int m) {
    if (m >= 1 && m <= 12)
      month = m;
  }
  int Year() { return year; }
  void Year(int y) { year = y; }

private:
  int day{1};
  int month{1};
  int year{0};
};

Date::Date(int day, int month, int year) {
  Day(day);
  Month(month);
  Year(year);
}

// Test in main
int main() {
  Date date(29, 8, 1981);
  assert(date.Day() == 29);
  assert(date.Month() == 8);
  assert(date.Year() == 1981);
}