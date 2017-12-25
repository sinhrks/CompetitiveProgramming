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

ll get_depth(ll n) {
  ll dep = 0;
  while (n > 0) {
    dep++;
    n /= 2;
  }
  return dep;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll N;
  cin >> N;

  ll depth = get_depth(N);
  bool tk_left = (depth % 2 == 0);

  ll x = 1;
  REP(i, depth) {
    if (i % 2 == 0) {
      if (tk_left) x *= 2;
      else x = x * 2 + 1;
      if (x > N) {
        cout << "Aoki" << endl;
        return 0;
      }
    } else {
      if (tk_left) x = x * 2 + 1;
      else x *= 2;
      if (x > N) {
        cout << "Takahashi" << endl;
        return 0;
      }
    }
  }
  return 0;
}
