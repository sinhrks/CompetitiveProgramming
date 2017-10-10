#include <algorithm>
#include <numeric>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
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

ull M = 1777777777;

// 場合の数
template <typename T>
T comb(T n, T k) {
  T r = 1;
  for (ull d = 1; d <= k; ++d) {
    r *= n--;
    r /= d;
  }
  return r;
}

// 完全順列
template <typename T>
T derangement(T N) {
  if (N <= 1) {
    return 0;
  } else if (N == 2) {
    return 1;
  }
  T p2 = 0, p1 = 1;
  for (T i = 3; i <= N; i++) {
    T n = (i - 1) * (p1 + p2);
    p2 = p1;
    p1 = n;
  }
  return p1;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ull N, K;
    cin >> N >> K;

    ull c1 = comb(N, K);
    ull c2 = derangement(K);

    cout << c1 % M * c2 % M << endl;
    return 0;
}
