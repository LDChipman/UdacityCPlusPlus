#include <cassert>
#include <string>
#include <vector>

class Date {
public:
  Date(int day, int month, int year);
  int Day() const { return day_; }
  void Day(int day);
  int Month() const { return month_; }
  void Month(int month);
  int Year() const { return year_; }
  void Year(int year);
  std::string String() const;

private:
  bool LeapYear(int year) const;
  int DaysInMonth(int month, int year) const;
  int day_{1};
  int month_{1};
  int year_{0};
};

Date::Date(int day, int month, int year) {
  Year(year);
  Month(month);
  Day(day);
}

bool Date::LeapYear(int year) const {
  if (year % 4 != 0)
    return false;
  else if (year % 100 != 0)
    return true;
  else if (year % 400 != 0)
    return false;
  else
    return true;
}

int Date::DaysInMonth(int month, int year) const {
  if (month == 2)
    return LeapYear(year) ? 29 : 28;
  else if (month == 4 || month == 6 || month == 9 || month == 11)
    return 30;
  else
    return 31;
}

void Date::Day(int day) {
  if (day >= 1 && day <= DaysInMonth(Month(), Year()))
    day_ = day;
}

void Date::Month(int month) {
  if (month >= 1 && month <= 12)
    month_ = month;
}

void Date::Year(int year) { year_ = year; }

std::string Date::String() const {

  std::string date = "";
  switch (month_) {
  case 1:
    date += "January ";
    break;
  case 2:
    date += "Febuary ";
    break;
  case 3:
    date += "March ";
    break;
  case 4:
    date += "April ";
    break;
  case 5:
    date += "May ";
    break;
  case 6:
    date += "June ";
    break;
  case 7:
    date += "July ";
    break;
  case 8:
    date += "August ";
    break;
  case 9:
    date += "September ";
    break;
  case 10:
    date += "October ";
    break;
  case 11:
    date += "November ";
    break;
  case 12:
    date += "December ";
    break;
  }
  date += std::to_string(day_);
  date += ", ";
  date += std::to_string(year_);
  return date;
}

// Test
int main() {
  Date date(29, 8, 1981);
  assert(date.String() == "August 29, 1981");
}