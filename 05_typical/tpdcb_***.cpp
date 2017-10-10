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

int dp[1001][1001] = {};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int A, B;
  cin >> A >> B;

  int a[1001] = {};
  int b[1001] = {};
  for (int i = 1; i <= A; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= B; i++) {
    cin >> b[i];
  }
  for (int i = 1; i <= A; i++) {
    if ((A + B - i) % 2 == 1) {
      dp[i][0] = dp[i - 1][0] + a[A + 1 - i];
    } else {
      dp[i][0] = dp[i - 1][0];
    }
  }
  for (int i = 1; i <= B; i++) {
    if ((A + B - i) % 2 == 1) {
      dp[0][i] = dp[0][i - 1] + b[B + 1 - i];
    } else {
      dp[0][i] = dp[0][i - 1];
    }
  }

  for (int i = 1; i <= A; i++) {
    for (int j = 1; j <= B; j++) {
      if ((A + B - (i + j)) % 2 == 1) {
        dp[i][j] = max(dp[i - 1][j] + a[A + 1 - i],
                       dp[i][j - 1] + b[B + 1 - j]);
      } else {
        dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }
  cout << dp[A][B] << endl;
  return 0;
}
