#include <cassert>
#include <iostream>

struct Date {
public:
  int GetDay() { return day; }
  int GetMonth() { return month; }
  int GetYear() { return year; }

  void SetDay(int newDay) {
    if (newDay >= 1 && newDay <= 31)
      day = newDay;
  }
  void SetMonth(int newMonth) {
    if (newMonth >= 1 && newMonth <= 12)
      month = newMonth;
  }
  void SetYear(int newYear) {
    if (newYear >= 0)
      year = newYear;
  }

private:
  int day{1};
  int month{1};
  int year{0};
};

int main() {
  Date date;
  date.SetDay(29);
  date.SetMonth(8);
  date.SetYear(1981);
  assert(date.GetDay() == 29);
  assert(date.GetMonth() == 8);
  assert(date.GetYear() == 1981);
  std::cout << date.GetDay() << "/" << date.GetMonth() << "/" << date.GetYear()
            << "\n";
}