#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <sstream>
#include <exception>
#include <iomanip>

using namespace std;

/**
 *  1. Реализовать разбор строки, после принятия через getline();               +
 *  2. Игнорирование пустой строки;                                             +
 *  3. Проверку даты на верность;                                               +
 *      - проверка формата даты                                         +
 *      - проверка месяца                                               +
 *      - проверка дня                                                  +
 *  4. Проверку команды на верность;                                            +-
 *  5. Реализовать весь функционал:                                             +-
 *      - добавление события:                        Add Дата Событие   +
 *      - удаление события:                          Del Дата Событие   +
 *      - удаление всех событий за конкретную дату:  Del Дата           +
 *      - поиск событий за конкретную дату:          Find Дата          -
 *      - печать всех событий за все даты:           Print              -
 *  6. Пройти готовые тесты от Coursera;                                        -
 *  7. Написать "документацию".                                                 +-
 */


/*
 * Необходимые для обработки даты функции.
 */
void CheckNextSymbol (stringstream& s) {
    /*
     * Проверяет, что разделитель между частями даты '-' и что следующий символ не бессмысленный.
     * Иначе кидает исключение.
     */
    if (s.peek() != '-') {
        throw exception();
    } else {
        s.ignore(1);
        if (!(((s.peek() >= 48) && (s.peek() <= 57)) || (s.peek() == '-') || (s.peek() == '+'))) {
            throw exception();
        }
    }
}
int NegativeCheck (stringstream& s) {
    /*
     * Проверяет, что после возможных знаков числа у нас будет цифра.
     */
    int result = 1;
    if (s.peek() == '-') {
        result = -1;
        s.ignore(1);
        if (!((s.peek() >= 48) && (s.peek() <= 57))) {
            throw exception();
        }
    } else if (s.peek() == '+') {
        s.ignore(1);
        if (!((s.peek() >= 48) && (s.peek() <= 57))) {
            throw exception();
        }
    }
    return result;
}

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
    Date (const string& input)  {
        stringstream s(input);
        try {
            s >> year;
            CheckNextSymbol(s);

            int NumberSign = NegativeCheck(s);
            int new_month = 0;
            s >> new_month;
            month = NumberSign*new_month;
            CheckNextSymbol(s);

            NumberSign = NegativeCheck(s);
            int new_day = 0;
            s >> new_day;
            day = NumberSign*new_day;
        } catch (exception& ex) {
            cout << "Wrong date format: " << input << endl;
            exit(0);
        }

        try {
            CheckMonth();
            CheckDay();
        } catch (exception& ex) {
            cout << ex.what() << endl;
            exit(0);
        }

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
    Date GetDate() const {
        return (Date(year, month, day));
    }
private:
    int year;
    int month;
    int day;

    void CheckMonth () {
        if ((month < 1) || (month > 12)) {
            throw runtime_error("Month value is invalid: " + to_string(month));
        }
    }
    void CheckDay () {
        if ((day < 1) || (day > 31)) {
            throw runtime_error("Day value is invalid: " + to_string(day));
        }
    }
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
bool operator!=(const Date& lhs, const Date& rhs) {
    return !(lhs == rhs);
}
ostream& operator<< (ostream& output, const Date& out) {
    output << setw(4) << setfill('0') << out.GetYear() << '-'
           << setw(2) << setfill('0') << out.GetMonth() << '-'
           << setw(2) << setfill('0') << out.GetDay();
    return output;
}

class Database {
public:
    void AddEvent(const Date& date, const string& event) {
        Base[date].insert(event);
    }
    bool DeleteEvent(const Date& date, const string& event) {
        if (Base.count(date) > 0) {
            auto it = Base[date].find(event);
            if (it != Base[date].end()) {
                Base[date].erase(it);
                return true;
            }
        }
        return false;
    }
    int  DeleteDate(const Date& date) {
        if (Base.count(date) > 0) {
            int result = Base[date].size();
            Base[date].clear();
            Base.erase(date);
            return result;
        }
        return 0;
    }
    void Find(const Date& date) const {
        if (Base.count(date) > 0) {
            for (const string& i: Base.at(date)) {
                cout << i << endl;
            }
        }
    }
    void Print() const {
        for (const auto& i: Base) {
            for (const string& j: i.second) {
                cout << i.first << " " << j << endl;
            }
        }
    }

private:
    map <Date, set<string>> Base;
};

vector<string> SplitInputString (const string& input) {
    vector<string> result;
    stringstream ss(input);

    while (!ss.eof()) {
        string s;
        ss >> s;
        result.push_back(s);
    }

    return result;
}

int main() {
    Database db;

    string input;
    while (getline(cin, input)) {
        if (input.empty()) {
            continue;
        }
        vector <string> InputStrings = SplitInputString(input);

        if (InputStrings[0] == "Add") {
            db.AddEvent(Date(InputStrings[1]), InputStrings[2]);
        } else if (InputStrings[0] == "Del") {
            if (InputStrings.size() == 2) {
                cout << "Deleted " << db.DeleteDate(Date(InputStrings[1])) << " events\n";
            } else {
                if (db.DeleteEvent(Date(InputStrings[1]), InputStrings[2])) {
                    cout << "Deleted successfully\n";
                } else {
                    cout << "Event not found\n";
                }
            }
        } else if (InputStrings[0] == "Find") {
            db.Find(Date(InputStrings[1]));
        } else if (InputStrings[0] == "Print") {
            db.Print();
        } else {
            string exc = "Unknown command: " + InputStrings[0];
            throw runtime_error(exc);
        }
    }

    return 0;
}
/*
 * Test 1
    Add 0-1-2 event1
    Add 1-2-3 event2
    Find 0-1-2

    Del 0-1-2
    Print
    Del 1-2-3 event2
    Del 1-2-3 event2

 * Test 2
   Add 0-13-32 event1

 */