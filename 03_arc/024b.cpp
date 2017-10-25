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

using namespace std;

int tree[100010] = {};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;

  int total = 0;
  REP(i, N) {
    cin >> tree[i];
    total += tree[i];
  }
  if (total == 0 || total == N) {
    cout << -1 << endl;
    return 0;
  }

  int mx = 0;
  int cnt = 1;
  for (int i = 1; i < 2 * N; i++) {
    if (tree[(i - 1) % N] == tree[i % N]) {
      cnt++;
    } else {
      cnt = 1;
    }
    mx = max(mx, cnt);
  }
  cout << (mx - 1) / 2 + 1 << endl;
  return 0;
}
