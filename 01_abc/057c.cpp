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

int digits(ll x) {
  int res = 1;
  while (x >= 10) {
    x /= 10;
    res++;
  }
  return res;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll N;
  cin >> N;

  int ans = digits(N);

  for (int i = 2; i <= (int)floor(sqrt(N)); i++) {
    // cout << N << " " << i << endl;
    if (N % i == 0) {
      int d = max(digits(i), digits(N / i));
      // cout << i << " " << d << endl;
      ans = min(ans, d);
    }
  }
  cout << ans << endl;
  return 0;
}
