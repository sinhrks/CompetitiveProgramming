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

  int A, B, C, D, E, F;
  cin >> A >> B >> C >> D >> E >> F;

  double limit = 100.0 * E / (100 + E);

  double pct = -1.;
  int w = 0;
  int s = 0;

  for (int a = 0; a <= F; a += A * 100) {
    for (int b = 0; b <= F; b += B * 100) {
      for (int c = 0; c <= F; c += C) {
        for (int d = 0; d <= F; d += D) {
          if (a + b > 0 && a + b + c + d <= F) {
            double tmp = 100.0 * (c + d) / (a + b + c + d);
            if (pct <= tmp && tmp <= limit) {
              pct = tmp;
              w = (a + b + c + d);
              s = c + d;
            }
          }
        }
      }
    }
  }

  cout << w << " " << s << endl;
  return 0;
}
