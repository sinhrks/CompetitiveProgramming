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

int H[1010][1010] = {};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int A, B;
  cin >> A >> B;

  int a[1010] = {};
  for (int i = 0; i < A; i++) {
    cin >> a[A - i];
  }
  int b[1010] = {};
  for (int i = 0; i < B; i++) {
    cin >> b[B - i];
  }

  bool sunuke = true;
  if ((A + B) % 2 == 0) {
    sunuke = !sunuke;
  }

  for (int i = 0; i <= A; i++) {
    for (int j = 0; j <= B; j++) {
      if (i == 0 && j == 0) continue;

      if (sunuke) {
        if (i == 0) {
          H[i][j] = H[i][j - 1] + b[j];
        } else if (j == 0) {
          H[i][j] = H[i - 1][j] + a[i];
        } else {
          H[i][j] = max(H[i - 1][j] + a[i],  H[i][j - 1] + b[j]);
        }
      } else {
        if (i == 0) {
          H[i][j] = H[i][j - 1] - b[j];
        } else if (j == 0) {
          H[i][j] = H[i - 1][j] - a[i];
        } else {
          H[i][j] = min(H[i - 1][j] - a[i],  H[i][j - 1] - b[j]);
        }
      }
      sunuke = !sunuke;
    }
  }
  ll ans = 0;
  for (int i = 0; i <= A; i++) {
    ans += a[i];
  }
  for (int i = 0; i <= B; i++) {
    ans += b[i];
  }

  cout << (ans + H[A][B]) / 2 << endl;
  return 0;
}
