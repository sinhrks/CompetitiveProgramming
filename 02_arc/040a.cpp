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

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;

  int red = 0;
  int blue = 0;
  REP(i, N) {
    string s;
    cin >> s;
    REP(j, s.size()) {
      if (s[j] == 'R') red++;
      if (s[j] == 'B') blue++;
    }
  }
  if (red > blue) {
    cout << "TAKAHASHI" << endl;
  } else if (red == blue) {
    cout << "DRAW" << endl;
  } else {
    cout << "AOKI" << endl;
  }
  return 0;
}
