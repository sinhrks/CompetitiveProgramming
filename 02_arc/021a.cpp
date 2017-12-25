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

int a[4][4] = {};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  REP(i, 4) {
    REP(j, 4) {
      cin >> a[i][j];
    }
  }
  bool can_continue = false;

  REP(i, 3) {
    REP(j, 4) {
      if (a[i][j] == a[i + 1][j]) {
        can_continue = true;
      }
    }
  }
  REP(i, 4) {
    REP(j, 3) {
      if (a[i][j] == a[i][j + 1]) {
        can_continue = true;
      }
    }
  }
  if (can_continue) {
    cout << "CONTINUE" << endl;
  } else {
    cout << "GAMEOVER" << endl;
  }
  return 0;
}
