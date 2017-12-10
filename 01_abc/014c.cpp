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

int cum[1000010] = {};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  REP(i, n) {
    int a, b;
    cin >> a >> b;
    cum[a]++;
    cum[b + 1]--;
  }
  int mx = 0;
  int c = 0;
  REP(i, 1000001) {
    c += cum[i];
    mx = max(mx, c);
  }

  cout << mx << endl;
  return 0;
}
