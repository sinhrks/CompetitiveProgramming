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

template<class T>
vector<T> eratosthenes(T n) {
  // ある数が素数でない場合に true
  vector<bool> dp(n, false);
  dp[0] = true;
  dp[1] = true;
  vector<T> primes;
  for (int i = 2; i < n; i++) {
    if (dp[i]) continue;
    primes.push_back(i);
    for (int j = i * 2; j < n; j += i) {
      dp[j] = true;
    }
  }
  return primes;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;

  vector<int> primes = eratosthenes(N + 1);
  int dp[20010] = {};
  REP(i, N + 1) {
    dp[i] = -1;
  }
  for (auto p : primes) {
    REPR(i, N) {
      if (dp[i] > 0 && i + p <= N) {
        dp[i + p] = max(dp[i + p], dp[i] + 1);
      }
    }
    dp[p] = max(dp[p], 1);
  }

  cout << dp[N] << endl;

  return 0;
}
