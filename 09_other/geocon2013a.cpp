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

using namespace std;

template <typename T>
vector<int> argsort(const vector<T> &values) {
  vector<int> idx(values.size());
  iota(idx.begin(), idx.end(), 0);

  sort(idx.begin(), idx.end(),
       [&values](size_t i1, size_t i2) { return values[i1] < values[i2]; });

  return idx;
}


int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N = 300;

  vector<int> X(300, 0);
  vector<int> Y(300, 0);

  for (int i = 0; i < N; i++) {
    cin >> X[i] >> Y[i];
  }
  vector<int> idx = argsort(X);

  cout << 100 << endl;
  for (int i = 0; i < 300; i += 3) {
    cout << idx[i] + 1 << " " << idx[i + 1] + 1 << " " << idx[i + 2] + 1<< endl;
  }
  return 0;
}
