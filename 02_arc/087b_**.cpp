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

bool dp[2][20000] = {};

bool check(const vector<int> &moves, int res) {
  REP(j, 20000) {
    dp[0][j] = false;
    dp[1][j] = false;
  }

  dp[1][10000] = true;
  REP(i, moves.size()) {
    REP(j, 20000) {
      dp[i % 2][j] = false;
    }
    REP(j, 20000) {
      if (dp[(i + 1) % 2][j]) {
        dp[i % 2][j + moves[i]] = true;
        dp[i % 2][j - moves[i]] = true;
      }
    }
  }
  return dp[(moves.size() - 1) % 2][10000 + res];
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  string S;
  int x, y;
  cin >> S;
  cin >> x >> y;
  S += 'T';

  vector<int> hmove;
  vector<int> vmove;
  bool is_h = true;
  int move = 0;
  REP(i, S.size()) {
    if (S[i] == 'T') {
      if (is_h) {
        hmove.push_back(move);
      } else {
        vmove.push_back(move);
      }
      is_h = !is_h;
      move = 0;
    } else {
      move++;
    }
  }
  if (check(hmove, x) && check(vmove, y)) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
