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

	t get(unsigned int i, unsigned int j) const {
		return matrix_[i][j];
	}

	t& set(unsigned int i, unsigned int j) {
		return matrix_[i][j];
	}

	template<unsigned int U, unsigned int V>
	Matrix<t, I, V> operator* (const Matrix<t, U, V>& other) {
		Matrix<t, I, V> result;
		if (J == U) {
			for (int h = 0; h < I; h++) {
				for (int k = 0; k < V; k++) {
					result.set(h, k) = 0;
					for (int l = 0; l < J; l++) {
						result.set(h, k) += matrix_[h][l] * other.get(l, k);
					}
				}
			}

		}
		return result;
	}


	template<unsigned int U, unsigned int V>
	Matrix<t, I, V>& operator*= (const Matrix<t, U, V>& other) {
		Matrix<t, I, V> temp = *this;
		if (J == U) {
			for (int h = 0; h < I; h++) {
				for (int k = 0; k < V; k++) {
					matrix_[h][k] = 0;
					for (int l = 0; l < J; l++) {
						matrix_[h][k] += temp.matrix_[h][l] * other.matrix_[l][k];
					}
				}
			}
		}
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

	t determinant() {
		if (I == J) {
			t det = 0;
			if (I == 1) {
				det = matrix_[0][0];
			}
			else if (I == 2) {
				det = matrix_[0][0] * matrix_[1][1] - matrix_[0][1] * matrix_[1][0];
			}
			else if (I == 3) {
				det = matrix_[0][0] * matrix_[1][1] * matrix_[2][2] + matrix_[1][0] * matrix_[2][1] * matrix_[0][2] + matrix_[2][0] * matrix_[0][1] * matrix_[1][2]
					- matrix_[0][2] * matrix_[1][1] * matrix_[2][0] - matrix_[1][2] * matrix_[2][1] * matrix_[0][0] - matrix_[2][2] * matrix_[0][1] * matrix_[1][0];
			}
			return det;
		}
		else
			cout << "No";
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

	Matrix <int, 3, 2> m5;
	cin >> m5;
	Matrix <int, 2, 3> mm;
	cin >> mm;
	cout << "*: " << m5 * mm;
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

	Matrix <int, 1, 1> m8;
	cout << "1 1" << endl;
	cin >> m8;
	cout << m8.determinant() << endl;
	Matrix <int, 2, 2> m9;
	cout << "2 2" << endl;
	cin >> m9;
	cout << m9.determinant() << endl;
	Matrix <int, 3, 3> m10;
	cout << "3 3" << endl;
	cin >> m10;
	cout << m10.determinant() << endl;
	Matrix <int, 3, 2> m11;
	cout << "3 2" << endl;
	cin >> m11;
	cout << m11.determinant() << endl;

}