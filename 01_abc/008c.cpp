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

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;

  int c[110] = {};
  REP(i, N) {
    cin >> c[i];
  }
  double e = 0;
  REP(i, N) {
    int m = 0;
    REP(j, N) {
      if (c[i] % c[j] == 0) m++;
    }
    // cout << i << " " << m << endl;
    if (m == 1) {
      e += 1;
    } else if (m % 2 == 0) {
      e += 0.5;
    } else {
      e += (double)(m + 1) / (2 * m);
    }
  }
  printf("%.10f\n", e);
  return 0;
}
