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

int dp[110][330] = {};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;

  int NG1, NG2, NG3;
  cin >> NG1 >> NG2 >> NG3;

  dp[0][N] = 1;
  REP(i, 100) {
    REP(j, N + 1) {
      if (j == NG1 || j == NG2 || j == NG3) continue;
      if (dp[i][j] > 0) {
        // cout << i << " " << j << endl;
        for (int k = 0; k <= 3; k++) {
          if (j - k == 0) {
            cout << "YES" << endl;
            return 0;
          } else if (j - k >= 0) {
            // cout << j << " " << k << " " << j - k << endl;
            dp[i + 1][j - k]++;
          }
        }
      }
    }
  }
  cout << "NO" << endl;
  return 0;
}
