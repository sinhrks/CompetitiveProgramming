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
class SegTree {
 public:
  // 要素数に対して必要な2進数の桁数を指定
  int N;
  vector<T> data;
  // 初期化に使う値を定義 (要変更)
  int init = 0;

  explicit SegTree(int n_) {
    N = 1;
    while (N < n_) {
      N *= 2;
    }
    data = vector<T>(2 * N - 1, init);
  }
  // 二つの区間の更新規則を定義 (要変更)
  T update_rule(T v1, T v2) {
    return v1 + v2;
  }
  void update(int i, T val) {
    i += N - 1;
    data[i] = val;
    while (i > 0) {
      i = (i - 1) / 2;
      data[i] = update_rule(data[i * 2 + 1], data[i * 2 + 2]);
    }
  }
  T query(T a, T b) {
    return internal_query(a, b, 0, 0, N);
  }
  T internal_query(T a, T b, int k, int l, int r) {
    if (r <= a || b <= l) return init;
    if (a <= l && r <= b) {
      return data[k];
    } else {
      int vl = internal_query(a, b, k * 2 + 1, l, (l + r) / 2);
      int vr = internal_query(a, b, k * 2 + 2, (l + r) / 2, r);
      return update_rule(vl, vr);
    }
  }
};


int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int Q, x, y, j;
  cin >> Q;

  SegTree<int> bt = SegTree<int>(200001);

  while (Q--) {
    cin >> x >> y;
    if (x == 1) {
      bt.update(y, 1);
    } else {
      int l = 0, r = bt.N;
      while (true) {
        int v = bt.query(0, (l + r) / 2);
        if (r - l <= 1) {
          break;
        } else if (v < y) {
          l = (l + r) / 2;
        } else {
          r = (l + r) / 2;
        }
      }
      cout << l << endl;
      bt.update(l, 0);
    }
  }
  return 0;
}
