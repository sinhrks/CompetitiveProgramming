#include <assert.h>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
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

#define INF 9999999999

using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, x;
  cin >> N >> x;

  ull a[2001] = {};
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }

  int mx = 0;
  int magic[2001] = {};
  ull cost[2001] = {};
  for (int i = 0; i < N; i++) {
    cost[i] = a[i];
  }

  for (int m = 0; m < N; m++) {
    for (int i = 0; i < N; i++) {
      ull tgt = cost[(i + m) % N] + x * magic[(i + m) % N];
      if (tgt >= m * x + a[i]) {
        magic[(i + m) % N] = m;
        cost[(i + m) % N] = a[i];
        mx = max(m, mx);
      }
    }
  }
  /*
  for (int i = 0; i < N; i++) {
    cout << cost[i] << " " << magic[i] << endl;
  }
  cout << mx << endl;
  */
  ull total = accumulate(cost, cost + N, 0LL);
  total += x * mx;

  cout << total << endl;
  return 0;
}
