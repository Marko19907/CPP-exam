#include <iostream>
#include <sstream>
#include <climits>
#include <vector>

using namespace std;

template <class T>
class Matrix {
public:
    vector<vector<T>> array;

    explicit Matrix(vector<vector<T>> input) : array(std::move(input)) {};


    Matrix<T> operator*(const Matrix<T> &other) {
        Matrix<T> current = *this;
        vector<vector<T>> result;

        for (int row = 0; row < toInt(other.getRowNumber()); row++) {
            result.emplace_back();
            for (int col = 0; col < toInt(current.getColumnNumber()); col++) {
                int resultCurr = 0;
                for (int temp = 0; temp < toInt(other.getColumnNumber()); temp++) {
                    resultCurr += current.array[row][temp] * other.array[temp][col];
                }
                result[row].emplace_back(resultCurr);
            }
        }

        Matrix<T> resultMatrix(result);
        return resultMatrix;
    }


    size_t getColumnNumber() const {
        return array.size();
    }

    size_t getRowNumber() const {
        return array[0].size();
    }


    string print() const {
        stringstream result;

        for (const auto& i : array) {
            result << "[  ";
            for (const auto& j : i) {
                result << j << " ";
            }
            result << " ]" << endl;
        }

        return result.str();
    }

    friend ostream &operator<<(ostream &out, Matrix<T> matrix) {
        out << matrix.print();
        return out;
    }

    int toInt(size_t i) const{
        if (i > UINT_MAX) {
            throw out_of_range("Out of range!");
        }
        return static_cast<int>(i);
    }
};

int main() {
    Matrix<int> m_a({
        {1, 2},
        {3, 4},
        {5, 6}
    });
    Matrix<int> m_b({
        {1, 2, 3},
        {4, 5, 6}
    });

    cout << m_a << endl;
    cout << m_b << endl;

    cout << m_a * m_b << endl;
    cout << m_b * m_a << endl;


    Matrix<int> m_c({
        {1, 2}
    });
    Matrix<int> m_d({
        {2},
        {2}
    });

    cout << m_c * m_d << endl;
    cout << m_d * m_c << endl;

    return 0;
}

/*
Correct printout:
[ 1 2 ]
[ 3 4 ]
[ 5 6 ]


[ 1 2 3 ]
[ 4 5 6 ]


[ 9 12 15 ]
[ 19 26 33 ]
[ 29 40 51 ]


[ 22 28 ]
[ 49 64 ]


[ 6 ]


[ 2 4 ]
[ 2 4 ]
*/
