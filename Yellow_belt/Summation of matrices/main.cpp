#include <iostream>
#include <vector>
#include <fstream>
#include <stdexcept>

using namespace std;

class Matrix {
public:
    Matrix () {
        num_col_ = 0;
        num_rows_ = 0;
    }
    Matrix (const int& num_rows, const int& num_col) {
        this->Reset(num_rows, num_col);
    }
    void Reset (int num_rows, int num_col) {
        if (num_rows < 0) {
            throw out_of_range("num_rows must be >= 0");
        } else if (num_col < 0) {
            throw out_of_range("num_col must be >= 0");
        } else if (num_rows == 0 || num_col == 0) {
            num_col = num_rows = 0;
        }
        M.assign(num_rows, vector<int> (num_col));
        num_col_ = num_col;
        num_rows_ = num_rows;
    }
    int At (const int& row, const int& col) const {
        return M.at(row).at(col);
    }
    int& At (const int& row, const int& col) {
        return M.at(row).at(col);
    }
    int GetNumRows () const {
        return num_rows_;
    }
    int GetNumColumns () const {
        return num_col_;
    }

private:
    int num_rows_ = 0;
    int num_col_ = 0;
    vector<vector<int>> M;
};

bool operator== (const Matrix& lhs, const Matrix& rhs) {
    if ((lhs.GetNumColumns() != rhs.GetNumColumns()) || (lhs.GetNumRows() != rhs.GetNumRows())) {
        return false;
    }

    for (auto i = 0; i < lhs.GetNumRows(); i++) {
        for (auto j = 0; j < rhs.GetNumColumns(); j++) {
            if (lhs.At(i, j) != rhs.At(i, j)) {
                return false;
            }
        }
    }

    return true;
}
Matrix operator+ (const Matrix& lhs, const Matrix& rhs) {
    if (lhs.GetNumColumns() != rhs.GetNumColumns()) {
        throw invalid_argument("Mismatched number of columns");
    } else if (lhs.GetNumRows() != rhs.GetNumRows()) {
        throw invalid_argument("Mismatched number of rows");
    }

    Matrix res(lhs.GetNumRows(), lhs.GetNumColumns());

    for (auto i = 0; i < res.GetNumRows(); i++) {
        for (auto j = 0; j < res.GetNumColumns(); j++) {
            res.At(i, j) = lhs.At(i, j) + rhs.At(i, j);
        }
    }

    return res;
}
istream& operator>> (istream& in, Matrix& m) {
    int num_rows, num_col = 0;
    in >> num_rows >> num_col;

    m.Reset(num_rows, num_col);
    for (auto i = 0; i < m.GetNumRows(); i++) {
        for (auto j = 0; j < m.GetNumColumns(); j++) {
            in >> m.At(i, j);
        }
    }

    return in;
}

ostream& operator<< (ostream& out, const Matrix& m) {
    out << m.GetNumRows() << " " << m.GetNumColumns() << endl;

    for (auto i = 0; i < m.GetNumRows(); i++) {
        for (auto j = 0; j < m.GetNumColumns(); j++) {
            out << m.At(i, j) << " ";
        }
        out << endl;
    }

    return out;
}

int main() {
    Matrix one;
    Matrix two;

    cin >> one >> two;
    cout << one + two << endl;
    return 0;
}
