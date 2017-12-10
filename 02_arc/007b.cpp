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

int disk[110] = {};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, M;
  cin >> N >> M;
  REP(i, N + 1) {
    disk[i] = i;
  }
  REP(i, M) {
    int d;
    cin >> d;
    // cout << disk[0] << " " << disk[d] << endl;
    REP(j, N + 1) {
      if (disk[j] == d) {
        swap(disk[0], disk[j]);
        break;
      }
    }
  }
  REP(i, N) {
    cout << disk[i + 1] << endl;
  }
  return 0;
}
