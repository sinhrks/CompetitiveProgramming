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
vector<int> argsort(const vector<T> &values) {
  vector<int> idx(values.size());
  iota(idx.begin(), idx.end(), 0);

  sort(idx.begin(), idx.end(),
       [&values](size_t i1, size_t i2) { return values[i1] < values[i2]; });

  return idx;
}

const double EPS = 1e-10;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, K;
  cin >> N >> K;

  vector<double> w(N, 0.0);
  vector<double> p(N, 0.0);
  vector<double> s(N, 0.0);

  REP(i, N) {
    cin >> w[i] >> p[i];
  }

  double left = 0.0;
  double right = 100.0;
  while (right - left > EPS) {
    double trial = (left + right) / 2.0;

    REP(i, N) {
      s[i] = (p[i] - trial) * w[i];
    }
    sort(s.begin(), s.end(), greater<double>());

    double remains = 0;
    REP(i, K) {
      remains += s[i];
    }
    if (remains < 0) {
      right = trial;
    } else {
      left = trial;
    }
  }
  printf("%.10f\n", left);
  return 0;
}
