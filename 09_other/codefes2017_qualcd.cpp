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

using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  string S;
  cin >> S;

  int chars[26] = {};

  REP(i, S.size()) {
    chars[S[i] - 'a']++;
  }
  int ans = 0;
  REP(i, 26) {
    if (chars[i] % 2 == 1) {
      ans++;
    }
  }
  cout << max(ans, 1) << endl;
  return 0;
}
