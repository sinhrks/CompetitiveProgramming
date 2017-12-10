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
#define DEBUG(vec) for (auto v : vec) { cout << v << " "; } cout << endl;

using namespace std;

ll juel[100010] = {};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, M;
  cin >> N >> M;
  ll total = 0;
  REP(i, N) {
    int l, r, s;
    cin >> l >> r >> s;
    l--;
    r--;
    total += s;
    juel[l] += s;
    juel[r + 1] -= s;
  }
  ll c = 0;
  ll mi = total;
  REP(i, M) {
    c += juel[i];
    mi = min(mi, c);
  }

  cout << total - mi << endl;
  return 0;
}
