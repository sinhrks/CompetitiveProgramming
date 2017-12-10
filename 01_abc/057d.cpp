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

ull v[51] = {};

template <typename T>
ull comb(T n, T k) {
  assert(n >= k);
  ull r = 1;
  for (ull d = 1; d <= static_cast<ull>(k); ++d) {
    r *= n--;
    r /= d;
  }
  return r;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll N, A, B;
  cin >> N >> A >> B;
  REP(i, N) {
    cin >> v[i];
  }
  sort(v, v + N, greater<ull>());

  ull total = 0;
  REP(i, A) {
    total += v[i];
  }
  printf("%.10lf\n", (double)total / A);

  ll ln = 0;
  ll lc = 0;
  REP(i, N) {
    if (v[i] == v[A - 1]) {
      ln++;
      if (i < A) lc++;
    }
  }
  if (v[0] == v[A - 1]) {
    ull c = 0;
    for (ll i = A; i <= min(ln, B); i++) {
      c += comb(ln, i);
    }
    printf("%lu\n", c);
  } else {
    printf("%lu\n", comb(ln, lc));
  }
  return 0;
}
