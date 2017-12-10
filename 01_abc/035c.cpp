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

int board[200010] = {};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, Q;
  cin >> N >> Q;
  REP(i, Q) {
    int l, r;
    cin >> l >> r;
    l--;
    board[l]++;
    board[r]--;
  }
  for (int i = 1; i < N; i++) {
    board[i] = board[i] + board[i - 1];
  }
  REP(i, N) {
    if (board[i] % 2 == 0) cout << "0";
    else cout << "1";
  }

  cout << endl;
  return 0;
}
