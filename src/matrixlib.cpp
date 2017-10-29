#include <assert.h>
#include <iostream>
#include <vector>

typedef long long ll;
typedef unsigned long long ull;

#define DEBUG(vec) for (auto v : vec) { cout << v << " "; } cout << endl;

using namespace std;

template <typename T>
struct Matrix {
  int rows, cols;
  vector<T> values;

  Matrix(int rows, int cols, vector<T> values) {
    assert(static_cast<int>(values.size()) == rows * cols);
    this->rows = rows;
    this->cols = cols;
    this->values = values;
  }
  Matrix(int rows, int cols, T value) {
    vector<T> values(rows * cols, value);
    this->rows = rows;
    this->cols = cols;
    this->values = values;
  }
  static Matrix<T> eye(int n) {
    assert(n > 0);
    vector<T> values(n * n, 0);
    for (int i = 0; i < n; i++) {
      values[i * n + i] = one();
    }
    return Matrix(n, n, values);
  }
  // 漸化式
  static Matrix<T> for_recurrence(vector<T> coefs) {
    int n = coefs.size();
    for (int i = 0; i < n - 1; i++) {
      for (int j = 0; j < n; j++) {
        coefs.push_back(i == j ? one() : 0);
      }
    }
    return Matrix(n, n, coefs);
  }
  // 漸化式の条件により書き換え
  inline static T one() {
    return 1;
  }
  inline static T add(T x, T y) {
    return x + y;
  }
  inline static T mul(T x, T y) {
    return x * y;
  }
  inline const T get_elem(int row, int col) const {
    return values[row * cols + col];
  }
  const vector<T> get_row(int row) const {
    assert(0 <= row && row < rows);
    vector<T> r;
    for (int i = 0; i < cols; i++) {
      r.push_back(get_elem(row, i));
    }
    return r;
  }
  const vector<T> get_col(int col) const {
    assert(0 <= col && col < cols);
    vector<T> c;
    for (int i = 0; i < rows; i++) {
      c.push_back(get_elem(i, col));
    }
    return c;
  }
  bool operator==(const Matrix<T> &rhs) {
    return (rows == rhs.rows && cols == rhs.cols && values == rhs.values);
  }
  // dot product
  Matrix<T> operator*(const Matrix<T> &rhs) {
    assert(cols == rhs.rows);
    vector<T> ans;
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < rhs.cols; j++) {
        T v = 0;
        for (int k = 0; k < cols; k++) {
          v = add(v, mul(get_elem(i, k), rhs.get_elem(k, j)));
        }
        ans.push_back(v);
      }
    }
    return Matrix(rows, rhs.cols, ans);
  }
  Matrix<T> pow(T n) {
    assert(rows == cols);
    Matrix<T> ans = Matrix<T>::eye(rows);
    Matrix<T> x(rows, cols, values);
    while (n > 0) {
      if ((n & 1) == 1) {
        ans = ans * x;
      }
      x = x * x;
      n >>= 1;
    }
    return ans;
  }
};

template <typename T>
ostream& operator<<(ostream& os, const Matrix<T> &m) {
  for (int i = 0; i < static_cast<int>(m.values.size()); i++) {
    os << m.values[i];
    if ((i + 1) % m.rows == 0) {
      os << endl;
    } else {
      os << " ";
    }
  }
  return os;
}

void test_matrix() {
  vector<int> values = {1, 2, 3, 4, 5, 6};
  Matrix<int> m(2, 3, values);
  assert(m.values == values);
  assert(m == m);

  vector<int> r0 = {1, 2, 3};
  assert(m.get_row(0) == r0);
  vector<int> r1 = {4, 5, 6};
  assert(m.get_row(1) == r1);

  vector<int> c0 = {1, 4};
  assert(m.get_col(0) == c0);
  vector<int> c1 = {2, 5};
  assert(m.get_col(1) == c1);
  vector<int> c2 = {3, 6};
  assert(m.get_col(2) == c2);

  Matrix<int> m2(2, 3, 5);
  vector<int> ev2 = {5, 5, 5, 5, 5, 5};
  Matrix<int> em2(2, 3, ev2);
  assert(m2 == em2);
}

void test_matrix_dot() {
  vector<int> values1 = {1, 2, 3, 4, 5, 6};
  Matrix<int> m1(2, 3, values1);

  vector<int> values2 = {2, 1, 3, 1, 5, 2};
  Matrix<int> m2(3, 2, values2);

  vector<int> ev1 = {23, 9, 53, 21};
  Matrix<int> em1(2, 2, ev1);
  assert(m1 * m2 == em1);
}

void test_matrix_eye() {
  Matrix<int> eye1 = Matrix<int>::eye(1);
  vector<int> ev1 = {1};
  Matrix<int> em1(1, 1, ev1);
  assert(eye1 == em1);

  Matrix<int> eye2 = Matrix<int>::eye(2);
  vector<int> ev2 = {1, 0, 0, 1};
  Matrix<int> em2(2, 2, ev2);
  assert(eye2 == em2);

  Matrix<int> eye3 = Matrix<int>::eye(3);
  vector<int> ev3 = {1, 0, 0, 0, 1, 0, 0, 0, 1};
  Matrix<int> em3(3, 3, ev3);
  assert(eye3 == em3);
}

void test_matrix_pow() {
  Matrix<int> eye3 = Matrix<int>::eye(3);
  assert(eye3.pow(10) == eye3);

  vector<int> values = {1, 2, 3, 4};
  Matrix<int> m(2, 2, values);

  vector<int> ev2 = {7, 10, 15, 22};
  Matrix<int> em2(2, 2, ev2);
  assert(m.pow(2) == em2);

  vector<int> ev5 = {1069, 1558, 2337, 3406};
  Matrix<int> em5(2, 2, ev5);
  assert(m.pow(5) == em5);

  vector<int> ev8 = {165751, 241570, 362355, 528106};
  Matrix<int> em8(2, 2, ev8);
  assert(m.pow(8) == em8);
}

void test_matrix_coef() {
  vector<int> values = {1, 2, 3};
  Matrix<int> m = Matrix<int>::for_recurrence(values);

  vector<int> ev = {1, 2, 3, 1, 0, 0, 0, 1, 0};
  Matrix<int> em = Matrix<int>(3, 3, ev);
  assert(m == em);
}

int main() {
  test_matrix();
  test_matrix_dot();
  test_matrix_eye();
  test_matrix_pow();
  test_matrix_coef();

  cout << "SUCCESS!!" << endl;
  return 0;
}
