//
// Created by tokar on 02.08.2020.
//

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <sstream>
#include <exception>

using namespace std;

/*
 * Необходимо придумать как и где проверять дату на верность и выбрасывать исключения.
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
    Date (const string& input) {
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

    /*
     * Подумать над GetDate(), в каком формате и PrintDate(), тоже над форматом.
     * Также возможно добавление других функций, которые в данный момент не видны необходимыми.
     */

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
//    string s;
//    while (getline(cin, s)) {
//        if (s == "") {
//            cout << "Empty string!\n";
//            continue;
//        }
//        if (s == "end") {
//            break;
//        }
//        vector<string> Input = SplitInputString(s);
//
//        Date now = Date(Input[1]);
//        cout << now.GetDay() << "." << now.GetMonth() << "." << now.GetYear() << endl;
//
//    }
    set<int> a = {1, 2, 3, 4, 5, 6};
    if (a.find(7) != a.end()) {
        cout << "All is Okay!\n";
    } else {
        cout << "Smth is going wrong!\n";
    }


    cout << "End" << endl;
    return 0;
}

/*
a 2017-3-4
b -2017-3-4

 */
