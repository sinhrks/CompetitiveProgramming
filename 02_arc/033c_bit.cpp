#include <assert.h>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
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

using namespace std;


template <typename T>
class BIT {
 public:
  int N;
  vector<T> data;

  explicit BIT(int n_) {
    N = 1;
    while (N < n_) {
      N *= 2;
    }
    data = vector<T>(N, 0);
  }
  T sum(T i) {
    T s = 0;
    while (i > 0) {
      s += data[i];
      i -= i & -i;
    }
    return s;
  }
  void add(int i, T val) {
    while (i <= N) {
      data[i] += val;
      i += i & -i;
    }
  }
  // 指定された値以上の要素が最初に現れる位置を返す
  T lower_bound(T val) {
    T tv = 0;
    int ent = 0;
    for (int i = __builtin_ctz(N); i >= 0; i--) {
      if (tv + data[ent + (1 << i)] < val) {
        tv += data[ent + (1 << i)];
        ent += (1 << i);
      }
    }
    if (tv < val) {
      ent++;
    }
    return ent;
  }
};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int Q, x, y, j;
  cin >> Q;

  BIT<int> bt = BIT<int>(200001);

  while (Q--) {
    cin >> x >> y;

    if (x == 1) {
      bt.add(y, 1);
    } else {
      j = bt.lower_bound(y);
      cout << j << endl;
      bt.add(j, -1);
    }
  }
  return 0;
}
