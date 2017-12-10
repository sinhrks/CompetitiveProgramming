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

int board[510][510] = {};
int ans[510][510] = {};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, M;
  cin >> N >> M;
  REP(i, N) {
    string s;
    cin >> s;
    REP(j, M) {
      board[i][j] = s[j] - '0';
    }
  }
  REP(i, N) {
    REP(j, M) {
      if (board[i][j] > 0) {
        ans[i + 1][j] = board[i][j];
        board[i + 1][j - 1] -= board[i][j];
        board[i + 1][j + 1] -= board[i][j];
        board[i + 2][j] -= board[i][j];
      }
    }
  }
  REP(i, N) {
    REP(j, M) {
      cout << ans[i][j];
    }
    cout << endl;
  }
  return 0;
}
