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

int T[30][200010] = {};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, C;
  cin >> N >> C;
  REP(i, N) {
    int s, t, c;
    cin >> s >> t >> c;
    c--;
    for (int j = s * 2 - 1; j <= t * 2; j++) {
      T[c][j] = 1;
    }
  }
  int ma = 0;
  REP(i, 200010) {
    int c = 0;
    REP(j, C) {
      c += T[j][i];
    }
    ma = max(ma, c);
  }

  cout << ma << endl;
  return 0;
}
