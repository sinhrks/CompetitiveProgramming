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

  bool water[3001] = {};
  bool sugar[3001] = {};

  for (int i = 0; i <= F; i += (100 * A)) {
    water[i] = true;
    for (int j = i; j <= F; j += (100 * B)) {
      water[j] = true;
    }
  }

  for (int i = 0; i <= F; i += C) {
    sugar[i] = true;
    for (int j = i; j <= F; j += D) {
      sugar[j] = true;
    }
  }

  double limit = 100.0 * E / (100 + E);

  double pct = -1.;
  int w = 0;
  int s = 0;

  for (int i = 0; i <= F; i++) {
    for (int j = 0; j <= F; j++) {
      if (water[i] && sugar[j] && (i + j) <= F) {
        double tmp = 100.0 * j / (i + j);
        if (tmp <= limit && pct < tmp) {
          w = i + j;
          s = j;

          pct = tmp;
        }
      }
    }
  }

  cout << w << " " << s << endl;
  return 0;
}
