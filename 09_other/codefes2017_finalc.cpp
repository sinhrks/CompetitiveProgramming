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

# define INF 0x3f3f3f3f

#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define DEBUG(vec) for (auto v : vec) { cout << v << " "; } cout << endl;

using namespace std;

int inv(int h) {
  if (h == 0) return 0;
  return 24 - h;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;

  int hour[24] = {};
  hour[12]++;

  REP(i, N) {
    int d;
    cin >> d;
    hour[(12 + d) % 24]++;
  }
  // d = 0
  REP(i, 24) {
    if (hour[i] > 2) {
      cout << 0 << endl;
      return 0;
    } else if (hour[i] == 2) {
      hour[i]--;
      hour[inv(i)]++;
    }
  }
  REP(i, 24) {
    if (hour[i] == 2) {
      cout << 0 << endl;
      return 0;
    }
  }

  for (int d = 1; d <= 12; d++) {
    for (int h = 0; h < 24; h++) {
      if (hour[h] == 0) continue;
      // cout << d << " " << h << endl;
      for (int k = h - d; k <= h + d; k++) {

        int hc = (k + 24) % 24;
        if (hc == h) continue;
        if (hour[hc] == 0) continue;

        if (hour[inv(hc)] > 0) {
          // cout << "a " << h << " " << hc << endl;
          cout << d << endl;
          return 0;

        } else {
          for (int l = inv(hc) - d; l <= inv(hc) + d; l++) {
            int hcc = (l + 24) % 24;
            // if (hcc == hc) continue;
            if (hour[hcc] > 0) {
              // cout << "b " << h << " " << hc << " " << hcc << " " << d << endl;
              cout << d << endl;
              return 0;
            }
          }
          hour[hc]--;
          hour[inv(hc)]++;
        }
      }
    }
  }

  return 0;
}
