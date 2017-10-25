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

int a[1010] = {};
int b[1010] = {};
int dp[1010][1010] = {};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int A, B;
  cin >> A >> B;

  REP(i, A) {
    cin >> a[i];
  }
  REP(i, B) {
    cin >> b[i];
  }

  int sunuke = (A + B) % 2;

  for (int i = 0; i <= A; i++) {
    for (int j = 0; j <= B; j++) {
      if (i == 0 && j == 0) continue;

      if (i == 0) {
        if ((i + j) % 2 == sunuke) {
          dp[i][j] = dp[i][j - 1] + b[B - j];
        } else {
          dp[i][j] = dp[i][j - 1];
        }
      } else if (j == 0) {
        if ((i + j) % 2 == sunuke) {
          dp[i][j] = dp[i - 1][j] + a[A - i];
        } else {
          dp[i][j] = dp[i - 1][j];
        }
      } else {
        if ((i + j) % 2 == sunuke) {
          dp[i][j] = max(dp[i - 1][j] + a[A - i], dp[i][j - 1] + b[B - j]);
        } else {
          dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]);
        }
      }
    }
  }
  cout << dp[A][B] << endl;
  return 0;
}
