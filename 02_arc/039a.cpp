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

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int A, B;
  cin >> A >> B;

  int ans = -5000;
  ans = max(ans, 900 + A % 100 - B);
  ans = max(ans, A / 100 * 100 + 90 + A % 10 - B);
  ans = max(ans, A / 10 * 10 + 9 - B);
  ans = max(ans, A - (100 + B % 100));
  ans = max(ans, A - (B / 100 * 100 + B % 10));
  ans = max(ans, A - (B / 10 * 10));
  cout << ans << endl;
  return 0;
}
