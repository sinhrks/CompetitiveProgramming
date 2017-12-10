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

bool F[10][110] = {};
int P[11][110] = {};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;

  REP(i, N) {
    REP(j, 10) {
      cin >> F[j][i];
    }
  }
  REP(i, N) {
    REP(j, 11) {
      cin >> P[j][i];
    }
  }
  int ma = -(1 << 30);
  for (int i = 1; i < (1 << 10); i++) {
    int m = 0;
    REP(j, N) {
      int c = 0;
      REP(k, 10) {
        if ((i & (1 << k)) > 0 && F[k][j]) {
          c++;
        }
      }
      m += P[c][j];
    }
    ma = max(ma, m);
  }

  cout << ma << endl;
  return 0;
}
