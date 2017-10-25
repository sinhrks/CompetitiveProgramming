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

ll f(ll x) {
  ll ans = 0;
  while (x > 0) {
    ans += x % 10;
    x /= 10;
  }
  return ans;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll N;
  cin >> N;

  vector<ll> ans;
  for (ll i = max(1LL, N - 9 * 17); i < N; i++) {
    if (i + f(i) == N) {
      ans.push_back(i);
    }
  }
  cout << ans.size() << endl;
  for (auto v : ans) {
    cout << v << endl;
  }
  return 0;
}
