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

// 素因数分解
vector<ll> get_primes(ll n) {
  vector<ll> result;

  for (ll i = 2; i <= sqrt(n); i++) {
    while ((n % i) == 0) {
      result.push_back(i);
      n /= i;
    }
  }
  if (n > sqrt(n)) {
    result.push_back(n);
  }
  return result;
}

int counts[1001] = {};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;

  for (int i = 1; i <= N; i++) {
    vector<ll> primes = get_primes(i);
    for (auto prime : primes) {
      counts[prime]++;
    }
  }
  ll ans = 1;
  REP(i, 1001) {
    ans *= counts[i] + 1;
    ans %= 1000000007;
  }
  cout << ans << endl;
  return 0;
}
