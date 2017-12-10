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

  int n;
  cin >> n;

  ll a[100001] = {};
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  ll op1 = 0;
  ll total1 = 0;
  for (int i = 0; i < n; i++) {
    total1 += a[i];
    if (i % 2 == 0) {
      if (total1 <= 0) {
        op1 += abs(total1) + 1;
        total1 = 1;
      }
    } else {
      if (total1 >= 0) {
        op1 += abs(total1) + 1;
        total1 = -1;
      }
    }
  }

  ll op2 = 0;
  ll total2 = 0;
  for (int i = 0; i < n; i++) {
    total2 += a[i];
    if (i % 2 == 0) {
      if (total2 >= 0) {
        op2 += abs(total2) + 1;
        total2 = -1;
      }
    } else {
      if (total2 <= 0) {
        op2 += abs(total2) + 1;
        total2 = 1;
      }
    }
  }

  cout << min(op1, op2) << endl;
  return 0;
}
