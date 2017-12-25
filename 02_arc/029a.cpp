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

int niku[4] = {};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;
  REP(i, N) {
    cin >> niku[i];
  }
  int niku1 = niku[0];
  int niku2 = niku[1];
  int niku3 = niku[2];
  int niku4 = niku[3];

  int ans = niku1 + niku2 + niku3 + niku4;
  ans = min(ans, max(niku1, niku2 + niku3 + niku4));
  ans = min(ans, max(niku2, niku1 + niku3 + niku4));
  ans = min(ans, max(niku3, niku1 + niku2 + niku4));
  ans = min(ans, max(niku4, niku1 + niku2 + niku3));

  ans = min(ans, max(niku1 + niku2, niku3 + niku4));
  ans = min(ans, max(niku1 + niku3, niku2 + niku4));
  ans = min(ans, max(niku1 + niku4, niku2 + niku3));

  cout << ans << endl;
  return 0;
}
