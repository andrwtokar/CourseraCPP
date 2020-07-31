#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;
// Реализуйте функции и методы классов и при необходимости добавьте свои

class Date {
public:
    Date () {
        year = 0;
        month = 0;
        day = 0;
    }

    Date (const int& new_year, const int& new_month, const int& new_day) {
        year = new_year;
        month = new_month;
        day = new_day;
    }
    int GetYear() const {
        return year;
    }
    int GetMonth() const {
        return month;
    }
    int GetDay() const {
        return day;
    }

private:
    int year;
    int month;
    int day;
};

bool operator<(const Date& lhs, const Date& rhs) {
    if (lhs.GetYear() != rhs.GetYear()) {
        return lhs.GetYear() < rhs.GetYear();
    } else  if (lhs.GetMonth() != rhs.GetMonth()) {
        return lhs.GetMonth() < rhs.GetMonth();
    } else {
        return lhs.GetDay() < rhs.GetDay();
    }
}

bool operator==(const Date& lhs, const Date& rhs) {
    return ((lhs.GetYear() == rhs.GetYear()) && (lhs.GetMonth() == rhs.GetMonth()) && (lhs.GetDay() == rhs.GetDay()));
}

class Database {
public:
      void AddEvent(const Date& date, const string& event) {

      }
      bool DeleteEvent(const Date& date, const string& event) {

      }
      int  DeleteDate(const Date& date) {

      }

      Database/*над этим ещё надо подумать*/ Find(const Date& date) const {

      }

      void Print() const {

      }

private:
    map <Date, vector <string>> Base;
};

int main() {
      Database db;

      string command;
      while (getline(cin, command)) {
        // Считайте команды с потока ввода и обработайте каждую
      }

      return 0;
}
