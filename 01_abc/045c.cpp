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

int num[10] = {};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  string s;
  cin >> s;
  REP(i, s.size()) {
    num[i] = s[i] - '0';
  }
  ll ma = 0;
  REP(i, 1 << (s.size() - 1)) {
    ll m = 0;
    ll c = 0;
    REP(j, s.size()) {
      c += num[j];
      if ((i & (1 << j)) > 0 || j == s.size() - 1) {
        m += c;
        c = 0;
      }
      c *= 10;
    }
    ma += m;
  }

  cout << ma << endl;
  return 0;
}
