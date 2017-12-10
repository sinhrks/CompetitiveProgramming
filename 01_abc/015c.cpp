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

int ans[6][128] = {};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  REP(i, 6) {
    REP(j, 128) {
      ans[i][j] = -1;
    }
  }

  int N, K;
  cin >> N >> K;
  ans[0][0] = 1;
  for (int i = 1; i <= N; i++) {
    REP(j, K) {
      int t;
      cin >> t;
      REP(p, 128) {
        if (ans[i - 1][p] > 0) {
          ans[i][p ^ t] = 1;
        }
      }
    }
  }
  if (ans[N][0] > 0) {
    cout << "Found" << endl;
  } else {
    cout << "Nothing" << endl;
  }
  return 0;
}
