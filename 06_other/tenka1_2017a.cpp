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

using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll N;
  cin >> N;

  for (ll h = 1; h <= 3500; h++) {
    for (ll n = h; n <= 3500; n++) {
      ll d = (4 * h * n - n * N - N * h);
      if (d > 0) {
        ll v = (h * n * N) / d;
        if (v > 0 && (4 * h * n * v / (h * n + n * v + v * h) == N)) {
          cout << h << " " << n << " " << v << endl;
          return 0;
        }
      }
    }
  }
  return 0;
}
