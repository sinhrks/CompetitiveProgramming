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

using namespace std;

// 座標圧縮
template <typename T>
struct Compressor {
  map<T, int> compressor;
  vector<T> extractor;

  explicit Compressor(vector<T> originals) {
    sort(originals.begin(), originals.end());
    originals.erase(unique(originals.begin(), originals.end()),
                    originals.end());

    extractor = vector<T>(originals.size(), 0);
    for (int i = 0; i < originals.size(); i++) {
      compressor[originals[i]] = i;
      extractor[i] = originals[i];
    }
  }
  int size() {
    return compressor.size();
  }
  int compress(T value) {
    return compressor[value];
  }
  vector<int> compress(const vector<T> &values) {
    // <int> を返したいので for_each は使えない
    vector<int> results(values.size());
    for (int i = 0; i < values.size(); i++) {
      results[i] = compress(values[i]);
    }
    return results;
  }
  // 座標圧縮後の各コードが、valuesの圧縮により現れるかどうかを返す
  vector<bool> compress_as_flag(const vector<T> &values) {
    vector<bool> results(this->size(), false);
    for (int i = 0; i < values.size(); i++) {
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

  int NA, NB;
  cin >> NA >> NB;

  vector<int> A(NA, 0);
  vector<int> B(NB, 0);
  vector<int> all(NA + NB, 0);

  REP(i, NA) {
    cin >> A[i];
    all[i] = A[i];
  }
  REP(i, NB) {
    cin >> B[i];
    all[NA + i] = B[i];
  }

  Compressor<int> c(all);
  vector<bool> ia = c.compress_as_flag(A);
  vector<bool> ib = c.compress_as_flag(B);
  int x = 0;
  int y = 0;
  REP(i, c.size()) {
    if (ia[i] && ib[i]) {
      x++;
    }
    y++;
  }
  printf("%.10f\n", 1.0 * x / y);
  return 0;
}
