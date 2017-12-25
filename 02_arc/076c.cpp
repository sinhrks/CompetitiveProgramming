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

struct FactorialTable {
  vector<ll> fact;
  vector<ll> inv;
  ll n;
  ll m;

  explicit FactorialTable(ll n, ll m) {
    this->n = n;
    this->m = m;
    fact = vector<ll>(n + 1, 0);
    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
      fact[i] = fact[i - 1] * i % m;
    }
    inv = vector<ll>(n + 1, 0);

    for (int i = 0; i <= n; i++) {
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
    assert(this->n > n);
    return fact[n];
  }
  // 組み合わせ nCk
  ll comb(int n, int k) {
    assert(this->n > n);
    assert(n >= k);
    return fact[n] * inv[k] % m * inv[n - k] % m;
  }
  // 重複組み合わせ nHr = (n + r + 1)Cr
  // n 種類のものから重複を許して r 個選ぶ場合の数
  ll mcomb(int n, int k) {
    return comb(n + k - 1, k);
  }
};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll N, M;
  cin >> N >> M;

  FactorialTable f(100010, MOD7);

  if (abs(N - M) > 1) {
    cout << 0 << endl;
    return 0;
  }
  ll ans = f.factorial(N) * f.factorial(M);
  ans %= MOD7;
  if (N == M) {
    ans *= 2;
    ans %= MOD7;
  }

  cout << ans << endl;
  return 0;
}
