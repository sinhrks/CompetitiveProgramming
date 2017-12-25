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

int a[100010] = {};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;
  REP(i, N) {
    int x;
    cin >> x;
    a[x]++;
  }
  ll ans = 1;
  if (N % 2 == 1 && a[0] != 1) ans = 0;

  for (int i = 1; i < N; i++) {
    if (i % 2 != N % 2) {
      if (a[i] != 2) ans = 0;
      ans *= 2;
      ans %= 1000000007;
    } else {
      if (a[i] != 0) ans = 0;
    }
  }

  cout << ans << endl;
  return 0;
}
