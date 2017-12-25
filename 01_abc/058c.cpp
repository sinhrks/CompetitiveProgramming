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

int current[26] = {};
int nex[26] = {};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;

  REP(i, 26) {
    current[i] = 100;
  }
  REP(i, N) {
    string s;
    cin >> s;

    REP(j, 26) {
      nex[j] = 0;
    }
    REP(j, s.size()) {
      nex[s[j] - 'a']++;
    }
    REP(j, 26) {
      current[j] = min(current[j], nex[j]);
    }
  }
  REP(i, 26) {
    REP(j, current[i]) {
      cout << (char)('a' + i);
    }
  }
  cout << endl;
  return 0;
}
