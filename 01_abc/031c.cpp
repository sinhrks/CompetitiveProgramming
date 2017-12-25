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

int a[50] = {};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;

  REP(i, N) {
    cin >> a[i];
  }

  int ma = -10000;
  REP(i, N) {
    int ao_ma = -10000;
    int tak_ma = -10000;
    REP(j, N) {
      if (i == j) continue;
      int tak = 0;
      int ao = 0;
      for (int k = min(i, j); k <= max(i, j); k++) {
        if ((k - min(i, j)) % 2 == 1) {
          ao += a[k];
        } else {
          tak += a[k];
        }
      }
      if (ao > ao_ma) {
        // cout << i << " " << j << endl;
        ao_ma = ao;
        tak_ma = tak;
      }
    }
    ma = max(ma, tak_ma);
  }

  cout << ma << endl;
  return 0;
}
