#include <cassert>
#include <stdexcept>
#include <string>

class Student {
private:
  std::string name_;
  int grade_;
  float gpa_;

public:
  Student(std::string name, int grade, float gpa) : name_(name) {
    SetGrade(grade);
    SetGpa(gpa);
  }

  std::string GetName() const { return name_; }
  int GetGrade() const { return grade_; }
  float GetGpa() const { return gpa_; }

  void SetName(std::string newName) { name_ = newName; }

  void SetGrade(int newGrade) {
    if (newGrade >= 0 && newGrade <= 12)
      grade_ = newGrade;
    else
      throw std::invalid_argument(
          "Cannot set grade to an integer less than 0 or greater than 12.");
  }

  void SetGpa(float newGpa) {
    if (newGpa >= 0.0 && newGpa <= 4.0)
      gpa_ = newGpa;
    else
      throw std::invalid_argument(
          "Cannot set gpa to an float less than 0 or greater than 4.0");
  }
};

int main() {
  Student student("Jonathan", 6, 2.5);
  assert(student.GetName() == "Jonathan");
  assert(student.GetGrade() == 6);
  assert(student.GetGpa() == 2.5);

  bool caught{false};
  try {
    Student invalid("Jake", -54, 8.3);
  } catch (...) {
    caught = true;
  }
  assert(caught);
}