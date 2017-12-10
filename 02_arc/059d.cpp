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

  string s;
  cin >> s;
  REP(i, s.size() - 1) {
    if (s[i] == s[i + 1]) {
      cout << i + 1 << " " << i + 2 << endl;
      return 0;
    }
    if (i < s.size() - 2) {
      if (s[i] == s[i + 2]) {
        cout << i + 1 << " " << i + 3 << endl;
        return 0;
      }
    }
  }
  cout << "-1 -1" << endl;
  return 0;
}
