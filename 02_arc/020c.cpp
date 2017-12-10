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

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n, c;
  cin >> n >> c;

  int a[100] = {};
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int ma = 1000000;
  for (int i = 1; i <= 10; i++) {
    for (int j = 1; j <= 10; j++) {
      if (i == j) continue;

      int cost = 0;
      for (int k = 0; k < n; k++) {
        if (k % 2 == 1) {
          if (a[k] != i) {
            cost += c;
          }
        } else {
          if (a[k] != j) {
            cost += c;
          }
        }
      }
      ma = min(ma, cost);
    }
  }

  cout << ma << endl;
  return 0;
}
