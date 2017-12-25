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

int l[50] = {};
int r[50] = {};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int L, R;
  cin >> L >> R;
  REP(i, L) {
    int t;
    cin >> t;
    l[t]++;
  }
  REP(i, R) {
    int t;
    cin >> t;
    r[t]++;
  }
  int ans = 0;
  REP(i, 50) {
    ans += min(l[i], r[i]);
  }

  cout << ans << endl;
  return 0;
}
