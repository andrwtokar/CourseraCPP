#include <iostream>
#include <sstream>
#include <set>
#include <map>
#include <vector>
#include <exception>

using namespace std;

class Rational {
public:
    Rational () {
        numerator = 0;
        denominator = 1;
        GSD = 0;
    }
    Rational (const int& new_numerator, const int& new_denominator) {
        if (new_denominator == 0) {
            throw invalid_argument("Invalid argument");
        }
        numerator = new_numerator;
        denominator = new_denominator;

        DifferenceFromZero();
        Sign();
        if (numerator < 0) {
            GSD = GreatestCommonDivisior((-1)*numerator, 1*denominator);
        } else{;
            GSD = GreatestCommonDivisior(numerator, denominator);
        }

        numerator = numerator/GSD;
        denominator = denominator/GSD;
    }
    int Numerator () const {
        return numerator;
    }
    int Denominator () const {
        return denominator;
    }
    istream& ReadRational(istream& input) {
        int new_numerator, new_denominator;
        input >> new_numerator;
        input.ignore(1);
        input >> new_denominator;

        if (new_denominator == 0) {
            throw invalid_argument("Invalid argument");
        }
        numerator = new_numerator;
        denominator = new_denominator;

        DifferenceFromZero();
        Sign();
        if (numerator < 0) {
            GSD = GreatestCommonDivisior((-1)*numerator, 1*denominator);
        } else{;
            GSD = GreatestCommonDivisior(numerator, denominator);
        }

        numerator = numerator/GSD;
        denominator = denominator/GSD;
        return input;
    }
private:
    int numerator;
    int denominator;
    int GSD;

    void DifferenceFromZero () {
        if (numerator == 0) {
            denominator = 1;
        }
    }
    void Sign () {
        if (denominator < 0) {
            numerator = (-1)*numerator;
            denominator = (-1)*denominator;
        }
    }
    static int GreatestCommonDivisior (int a, int b) {
        if (a % b == 0)
            return b;
        if (b % a == 0)
            return a;
        if (a > b)
            return GreatestCommonDivisior(a%b, b);
        return GreatestCommonDivisior(a, b%a);
    }
};

bool operator== (const Rational& lhs, const Rational& rhs) {
    return ((lhs.Numerator() == rhs.Numerator()) && (lhs.Denominator() == rhs.Denominator()));
}
Rational operator+ (const Rational& lhs, const Rational& rhs) {
    int numer = lhs.Numerator()*rhs.Denominator() + rhs.Numerator()*lhs.Denominator();
    int denomir = lhs.Denominator()*rhs.Denominator();
    return {numer, denomir};
}
Rational operator- (const Rational& lhs, const Rational& rhs) {
    int numer = lhs.Numerator() * rhs.Denominator() - rhs.Numerator() * lhs.Denominator();
    int denomir = lhs.Denominator() * rhs.Denominator();
    return {numer, denomir};
}
Rational operator* (const Rational& lhs, const Rational& rhs) {
    int numer = lhs.Numerator()*rhs.Numerator();
    int denomir = lhs.Denominator()*rhs.Denominator();
    return {numer, denomir};
}
Rational operator/ (const Rational& lhs, const Rational& rhs) {
    if (rhs.Numerator() == 0) {
        throw domain_error("Division by zero");
    }
    int numer = lhs.Numerator()*rhs.Denominator();
    int denomir = lhs.Denominator()*rhs.Numerator();
    return {numer, denomir};
}
istream& operator>> (istream& input, Rational& r) {
    return r.ReadRational(input);
}
ostream& operator<< (ostream& output, const Rational& r) {
    output << r.Numerator() << "/" << r.Denominator();
    return output;
}
bool operator< (const Rational& lhs, const Rational& rhs) {
    if (lhs == rhs) {
        return false;
    }
    if (lhs.Numerator() == 0) {
        return rhs.Numerator() > 0;
    } else if (lhs.Numerator() > 0) {
        if (rhs.Numerator() == 0) {
            return false;
        } else if (rhs.Numerator() < 0) {
            return false;
        } else if (rhs.Numerator() > 0) {
            Rational r = lhs/rhs;
            return ((r.Numerator()/r.Denominator()) < 1);
        }
    } else if (lhs.Numerator() < 0) {
        if (rhs.Numerator() == 0) {
            return true;
        } else if (rhs.Numerator() > 0) {
            return true;
        } else if (rhs.Numerator() < 0) {
            Rational r = lhs/rhs;
            return (double(r.Numerator()/r.Denominator()) > 1);
        }
    }
}



//Another comparison operators.

/*bool operator> (const Rational& lhs, const Rational& rhs) {
    Rational result = lhs/rhs;
    return (result.Numerator()/result.Denominator() > 1);
}
bool operator!= (const Rational& lhs, const Rational& rhs) {
    return !(lhs == rhs);
}
bool operator<= (const Rational& lhs, const Rational& rhs) {
    Rational result = lhs/rhs;
    return (result.Numerator()/result.Denominator() <= 1);
}
bool operator>= (const Rational& lhs, const Rational& rhs) {
    Rational result = lhs/rhs;
    return (result.Numerator()/result.Denominator() >= 1);
}*/



//This main function for check right work of iostream operations.


int main() {
    Rational a = Rational();
    Rational b = Rational();
    char oper;

    try {
        cin >> a >> oper >> b;

        if (oper == '+') {
            cout << a + b << endl;
        } else if (oper == '-') {
            cout << a - b << endl;
        } else if (oper == '*') {
            cout << a*b << endl;
        } else if (oper == '/') {
            cout << a/b << endl;
        }

    } catch (exception& e) {
        cout << e.what() << endl;
    }
}



//This main function for check right work of throw exception.

/*
int main() {
    try {
        Rational r(1, 0);
        cout << "Doesn't throw in case of zero denominator" << endl;
        return 1;
    } catch (invalid_argument& e) {
    }

    try {
        auto x = Rational(1, 2) / Rational(0, 1);
        cout << "Doesn't throw in case of division by zero" << endl;
        return 2;
    } catch (domain_error& e) {
    }

    cout << "OK" << endl;
    return 0;
}*/



//This main function for check right work comparison operator.

/*
int main() {
    {
        const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
        if (rs.size() != 3) {
            cout << "Wrong amount of items in the set" << endl << "Size: " << rs.size() << endl;
            for (auto i: rs) {
                cout << i << endl;
            }

            return 1;
        }

        for (auto i: rs) {
            cout << "else" << i << endl;
        }

        vector<Rational> v;
        for (auto x : rs) {
            v.push_back(x);
        }
        if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}}) {
            cout << "Rationals comparison works incorrectly" << endl;
            return 2;
        }
    }

    {
        map<Rational, int> count;
        ++count[{1, 2}];
        ++count[{1, 2}];

        ++count[{2, 3}];

        if (count.size() != 2) {
            cout << "Wrong amount of items in the map" << endl;
            return 3;
        }
    }

    cout << "OK" << endl;
    return 0;
}
*/


