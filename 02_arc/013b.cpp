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

  int C;
  cin >> C;

  int x = 0, y = 0, z = 0;
  for (int i = 0; i < C; i++) {
    vector<int> v(3, 0);
    cin >> v[0] >> v[1] >> v[2];
    sort(v.begin(), v.end());
    x = max(x, v[0]);
    y = max(y, v[1]);
    z = max(z, v[2]);
  }

  cout << x * y * z << endl;
  return 0;
}
