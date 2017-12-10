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

# define INF 0x3f3f3f3f

#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define DEBUG(vec) for (auto v : vec) { cout << v << " "; } cout << endl;

using namespace std;

template <typename T>
vector<T> uniquify(vector<T> values) {
  sort(values.begin(), values.end());
  values.erase(unique(values.begin(), values.end()), values.end());
  return values;
}

// 座標圧縮
template <typename T>
struct Compressor {
  map<T, int> compressor;
  vector<T> extractor;

  explicit Compressor(vector<T> originals) {
    vector<T> u = uniquify(originals);

    extractor = vector<T>(u.size(), 0);
    for (int i = 0; i < static_cast<int>(u.size()); i++) {
      compressor[u[i]] = i;
      extractor[i] = u[i];
    }
  }
  int size() {
    return static_cast<int>(compressor.size());
  }
  int compress(T value) {
    return compressor[value];
  }
  vector<int> compress(const vector<T> &values) {
    // <int> を返したいので for_each は使えない
    vector<int> results(values.size());
    for (int i = 0; i < static_cast<int>(values.size()); i++) {
      results[i] = compress(values[i]);
    }
    return results;
  }
  // 座標圧縮後の各コードが、valuesの圧縮により現れるかどうかを返す
  vector<bool> compress_as_flag(const vector<T> &values) {
    vector<bool> results(this->size(), false);
    for (int i = 0; i < static_cast<int>(values.size()); i++) {
      results[compress(values[i])] = true;
    }
    return results;
  }
  T extract(int index) {
    return extractor[index];
  }
};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;
  vector<int> A(N, 0);
  REP(i, N) {
    cin >> A[i];
  }
  Compressor<int> c(A);
  vector<int> idx = c.compress(A);

  for (auto i : idx) {
    cout << i << endl;
  }

  return 0;
}
