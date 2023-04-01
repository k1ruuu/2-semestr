#include <iostream>
using namespace std;

template<typename t, unsigned int I, unsigned int J>
class Matrix {
private:

	t matrix_[I][J];
	unsigned int i = I;
	unsigned int j = J;
	template<typename t, unsigned int I, unsigned int J>
	friend ostream& operator<< (ostream& out, const Matrix<t, I, J>& mat);
	template<typename t, unsigned int I, unsigned int J>
	friend istream& operator>> (istream& in, Matrix<t, I, J>& mat);

public:
	Matrix() = default;

	Matrix(const Matrix& other) {
		for (int h = 0; h < i; h++) {
			for (int k = 0; k < j; k++) {
				matrix_[h][k] = other.matrix_[h][k];
			}
		}
	}

	Matrix& operator= (const Matrix<t, I, J>& other) {
		for (int h = 0; h < i; h++) {
			for (int k = 0; k < j; k++) {
				matrix_[h][k] = other.matrix_[h][k];
			}
		}
		return *this;
	}

	Matrix operator+ (const Matrix<t, I, J>& other) {
		for (int h = 0; h < i; h++) {
			for (int k = 0; k < j; k++) {
				matrix_[h][k] += other.matrix_[h][k];
			}
		}
		return *this;
	}

	Matrix& operator+= (const Matrix<t, I, J>& other) {
		for (int h = 0; h < i; h++) {
			for (int k = 0; k < j; k++) {
				matrix_[h][k] += other.matrix_[h][k];
			}
		}
		return *this;
	}

	Matrix operator* (const Matrix<t, I, J>& other) {
		Matrix<t, I, J> result;
		for (int h = 0; h < I; h++) {
			for (int k = 0; k < J; k++) {
				result.matrix_[h][k] = 0;
				for (int l = 0; l < I; l++) {
					result.matrix_[h][k] += matrix_[h][l] * other.matrix_[l][k];
				}
			}
		}
		return result;
	}

	Matrix& operator*= (const Matrix<t, I, J>& other) {
		Matrix<t, I, J> result;
		for (int h = 0; h < I; h++) {
			for (int k = 0; k < J; k++) {
				result.matrix_[h][k] = 0;
				for (int l = 0; l < I; l++) {
					result.matrix_[h][k] += matrix_[h][l] * other.matrix_[l][k];
				}
			}
		}
		*this = result;
		return *this;
	}

	Matrix& operator++ (t) {
		for (int h = 0; h < i; h++) {
			for (int k = 0; k < j; k++) {
				++matrix_[h][k];
			}
		}
		return *this;
	}

	auto& operator[](int index) {
		if (index < 0 || index >= I) {
			throw out_of_range("index out of range");
		}
		return matrix_[index];
	}

	~Matrix(){}

};
template<typename t, unsigned int I, unsigned int J>
ostream& operator<< (ostream& out, const Matrix<t, I, J>& mat) {
	for (int h = 0; h < I; h++) {
		for (int k = 0; k < J; k++) {
			out << mat.matrix_[h][k] << " ";
		}
		cout << endl;
	}
	return out;
}

template<typename t, unsigned int I, unsigned int J>
istream& operator>> (istream& in, Matrix<t, I, J>& mat) {
	for (int h = 0; h < I; h++) {
		for (int k = 0; k < J; k++) {
			in >> mat.matrix_[h][k];
		}
	}
	return in;
}

int main() {

	Matrix <int, 2, 2> m1;
	cin >> m1;
	cout << m1;
	cout << endl;

	Matrix <int, 2, 2> m2 = m1;
	cout << m2;
	cout << endl;

	Matrix <int, 2, 2> m3;
	m3 = m2 + m1;
	cout << m3;
	cout << endl;

	Matrix <int, 2, 2> m4;
	m4 = m1;
	m4 += m3;
	cout << m4;
	cout << endl;

	Matrix <int, 2, 2> m5;
	m5 = m1;
	Matrix <int, 2, 2> m6;
	m6 = m1 * m5;
	cout << m6;
	cout << endl;
	
	Matrix <int, 2, 2> m7;
	m7 = m1;
	m7 *= m1;
	cout << m7;
	cout << endl;
	m7++;
	cout << m7;
	cout << endl;
	cout << m7[1][1];
	cout << endl;


}