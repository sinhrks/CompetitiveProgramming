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

bool score[10010] = {};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;

  score[0] = true;
  REP(i, N) {
    int s;
    cin >> s;
    REPR(j, 10000) {
      if (score[j]) {
        score[j + s] = true;
      }
    }
  }
  REPR(i, 10000) {
    if (score[i] && i %10 > 0) {
      cout << i << endl;
      return 0;
    }
  }
  cout << 0 << endl;
  return 0;
}
