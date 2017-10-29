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

  double t[110] = {};
  double v[110] = {};

  REP(i, N) {
    cin >> t[i + 1];
  }
  REP(i, N) {
    cin >> v[i + 1];
  }
  for (int i = N + 1; i > 0; i--) {
    if (v[i] < v[i - 1] - t[i - 1]) {
      v[i - 1] = v[i] + t[i - 1];
    }
    // cout << v[i] << endl;
  }

  double run[20010] = {};
  int tim = 1;
  double current = 0;
  double area = 0;
  for (int i = 1; i <= N; i++) {
    // double current = run[i - 1];
    double current_lim = v[i];
    double next_lim = v[i + 1];

    REP(j, t[i]) {
      if (current - (t[i] - j) + 1 > next_lim) {
        run[tim] = current - 1;
      } else if (current + 1 <= current_lim &&
                 current + 1 - (t[i] - j) + 1 > next_lim) {
        run[tim] = current;
        // cout << "x: " << area << endl;
        area += 0.5;
      } else {
        run[tim] = min(current_lim, current + 1);
      }
      current = run[tim];
      // cout << current << " " << area << endl;
      area += run[tim] * 2;
      tim++;
    }
  }
  printf("%.10f\n", area / 2);
  return 0;
}
