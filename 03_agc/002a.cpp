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

  ll a, b;
  cin >> a >> b;
  if (a > 0 && b > 0) {
    cout << "Positive" << endl;
  } else if (a <= 0 && 0 <= b) {
    cout << "Zero" << endl;
  } else {
    if ((b - a) % 2 == 0) {
      cout << "Negative" << endl;
    } else {
      cout << "Positive" << endl;
    }
  }
  return 0;
}
