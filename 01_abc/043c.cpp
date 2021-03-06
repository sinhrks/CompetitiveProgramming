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

int a[100] = {};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;
  REP(i, N) {
    cin >> a[i];
  }
  ll ans = 40000000;
  for (int i = -100; i <= 100; i++) {
    ll c = 0;
    REP(j, N) {
      c += (a[j] - i) * (a[j] - i);
    }
    ans = min(ans, c);
  }

  cout << ans << endl;
  return 0;
}
