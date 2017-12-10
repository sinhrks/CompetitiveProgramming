#include <assert.h>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <algorithm>
#include <numeric>
#include <functional>
#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <complex>
#include <bitset>
typedef long long ll;
typedef unsigned long long ull;

#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
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
  inline static T one() {
    return 0xffffffff;
  }
  inline static T add(T x, T y) {
    return x ^ y;
  }
  inline static T mul(T x, T y) {
    return x & y;
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

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int K, M;
  cin >> K >> M;

  vector<unsigned int> a;
  vector<unsigned int> c;
  REP(i, K) {
    unsigned int aa;
    cin >> aa;
    a.push_back(aa);
  }
  REP(i, K) {
    unsigned int cc;
    cin >> cc;
    c.push_back(cc);
  }
  if (M < K) {
    cout << a[M - 1] << endl;
    return 0;
  }

  reverse(a.begin(), a.end());
  // reverse(c.begin(), c.end());

  Matrix<unsigned int> m = Matrix<unsigned int>::for_recurrence(c);
  Matrix<unsigned int> p = m.pow(M - K);
  Matrix<unsigned int> am(a.size(), 1, a);
  Matrix<unsigned int> res = p * am;

  cout << res.get_elem(0, 0) << endl;
  return 0;
}
