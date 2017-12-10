#include <assert.h>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
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

ll dp[51][2500] = {};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, A;
  cin >> N >> A;

  int x[51] = {};
  for (int i = 1; i <= N; i++) {
    cin >> x[i];
  }
  for (int i = 1; i <= N; i++) {
    for (int j = i - 1; j > 0; j--) {
      for (int k = 0; k <= 2500; k++) {
        if (dp[j][k] > 0) {
          dp[j + 1][k + x[i]] += dp[j][k];
        }
      }
    }
    dp[1][x[i]]++;
  }
  ll cnt = 0;
  for (int i = 0; i <= N; i++) {
    for (int k = 0; k <= 2500; k++) {
      if (dp[i][k] > 0 && k / i == A && k % i == 0) {
        cnt += dp[i][k];
      }
    }
  }

  cout << cnt << endl;
  return 0;
}
