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

const ll MOD7 = 1000000007;

ll mod_pow(ll x, ll n) {
  ll ans = 1;
  while (n > 0) {
    if ((n & 1) == 1) ans = ans * x % MOD7;
    x = x * x % MOD7;
    n >>= 1;
  }
  return ans;
}

int P[200010] = {};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;
  REP(i, N) {
    cin >> P[i + 1];
  }
  ll ans = mod_pow(2, N);
  cout << ans << endl;

  int parent = 0;
  int idx = 0;
  while (idx < N) {
    int n = 0;
    if (P[idx] <= parent) {
      idx++;
      n++;
    }
    cout << n << " " << mod_pow(2, N - n + 1) << endl;
    ans += mod_pow(2, N - n + 1) * n % MOD7;
    ans %= MOD7;
    parent = idx;
  }
  cout << ans << endl;
  return 0;
}
