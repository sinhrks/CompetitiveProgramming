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

using namespace std;

const ll MOD7 = 1000000007;

struct FactorialTable {
  vector<ll> fact;
  vector<ll> inv;
  ll m;

  explicit FactorialTable(ll n, ll m) {
    this->m = m;
    fact = vector<ll>(n + 1, 0);
    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
      fact[i] = fact[i - 1] * i % m;
    }
    inv = vector<ll>(n + 1, 0);

    for (int i = n - 1; i >= 0; i--) {
      inv[i] = mod_pow(fact[i], m - 2);
    }
    /*
    inv[n] = mod_pow(fact[n], m - 2);
    for (int i = n - 1; i >= 0; i--) {
      inv[i] = inv[i + 1] * (i + 1) % m;
    }
    */

  }
  ll mod_pow(ll x, ll n) {
    ll ans = 1;
    while (n > 0) {
      if ((n & 1) == 1) ans = ans * x % m;
      x = x * x % m;
      n >>= 1;
    }
    return ans;
  }
  ll factorial(int n) {
    return fact[n];
  }
  ll comb(int n, int k) {
    return fact[n] * inv[k] % m * inv[n - k] % m;
  }
};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int W, H;
  cin >> W >> H;

  FactorialTable f(W + H, MOD7);

  cout << f.comb(W - 1 + H - 1, W - 1) << endl;
  return 0;
}
