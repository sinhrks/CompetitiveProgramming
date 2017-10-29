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

int c[30010] = {};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;

  REP(i, N) {
    cin >> c[i];
  }
  int cnt = 0;
  int v = c[0];
  REP(i, N) {
    if (v > c[i]) {
      cnt++;
    }
    v = max(v, c[i]);
  }

  cout << cnt << endl;
  return 0;
}
