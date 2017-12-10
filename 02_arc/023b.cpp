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

int A[1010][1010];

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int R, C, D;
  cin >> R >> C >> D;

  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      cin >> A[i][j];
    }
  }

  int mx = 0;
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j ++) {
      if (i + j <= D && (i + j) % 2 == D % 2) {
        mx = max(mx, A[i][j]);
      }
    }
  }

  cout << mx << endl;
  return 0;
}
