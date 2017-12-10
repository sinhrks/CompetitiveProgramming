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

ll a[5010] = {};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, K;
  cin >> N >> K;
  ll tot = 0;
  REP(i, N) {
    cin >> a[i];
    tot += a[i];
  }
  if (tot < K) {
    cout << N << endl;
    return 0;
  }
  sort(a, a + N);

  int s = 0;
  int e = 0;
  int ans = 0;
  while (s < N) {
    ll total = 0;
    while (total < K && s < N) {
      total += a[s];
      s++;
    }
    while (total >= K && e < N) {
      // cout << total << endl;
      total -= a[e];
      e++;
      ans++;
    }
    ans--;
    // cout << s << " " << e << endl;
  }

  cout << ans << endl;
  return 0;
}
