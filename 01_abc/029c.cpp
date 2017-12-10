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

int N;
string convert(int ans) {
  string result = "";
  REP(i, N) {
    result = (char)('a' + ans % 3) + result;
    ans /= 3;
  }
  return result;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> N;

  int total = 1;
  REP(i, N) {
    total *= 3;
  }
  REP(i, total) {
    cout << convert(i) << endl;
  }
  return 0;
}
