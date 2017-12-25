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

int dist(int x1, int y1, int x2, int y2) {
  return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int x1, y1, r;
  cin >> x1 >> y1 >> r;
  int x2, y2, x3, y3;
  cin >> x2 >> y2 >> x3 >> y3;

  if (x1 - x2 >= r && x3 - x1 >= r && y1 - y2 >= r && y3 - y1 >= r) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
  }
  if (dist(x1, y1, x2, y2) <= r * r &&
      dist(x1, y1, x2, y3) <= r * r &&
      dist(x1, y1, x3, y2) <= r * r &&
      dist(x1, y1, x3, y3) <= r * r) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
  }
  return 0;
}
