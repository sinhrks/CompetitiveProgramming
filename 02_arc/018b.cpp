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

using namespace std;

ll triangle(ll ax, ll ay, ll bx, ll by, ll cx, ll cy) {
  return abs(ax * (by - cy) + bx * (cy - ay) + cx * (ay - by));
}


int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;

  ll X[110] = {};
  ll Y[110] = {};

  for (int i = 0; i < N; i++) {
    cin >> X[i] >> Y[i];
  }

  int cnt = 0;
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      for (int k = j + 1; k < N; k++) {
        ll f = triangle(X[i], Y[i], X[j], Y[j], X[k], Y[k]);
        if (f > 0 && f % 2 == 0) {
          cnt++;
        }
      }
    }
  }
  cout << cnt << endl;
  return 0;
}
