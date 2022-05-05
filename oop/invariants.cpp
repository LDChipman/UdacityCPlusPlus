#include <cassert>
#include <iostream>

class Date {
private:
  int day_{1};
  int month_{1};
  int year_{0};

public:
  // Getters
  int GetDay() { return day_; }
  int GetMonth() { return month_; }
  int GetYear() { return year_; }

  // Setters
  void SetDay(int newDay) {
    switch (month_) {
    case 2:
      if (newDay >= 1 && newDay <= 29)
        day_ = newDay;
      return;
    case 4:
    case 6:
    case 9:
    case 11:
      if (newDay >= 1 && newDay <= 30)
        day_ = newDay;
      return;
    default:
      if (newDay >= 1 && newDay <= 31)
        day_ = newDay;
      return;
    }
  }
  void SetMonth(int newMonth) {
    if (newMonth >= 1 && newMonth <= 12)
      month_ = newMonth;
  }
  void SetYear(int newYear) { year_ = newYear; }
};

// Test in main
int main() {
  Date date;
  date.SetDay(-1);
  date.SetMonth(14);
  date.SetYear(2000);
  assert(date.GetDay() != -1);
  assert(date.GetMonth() != 14);
  assert(date.GetYear() == 2000);
}
