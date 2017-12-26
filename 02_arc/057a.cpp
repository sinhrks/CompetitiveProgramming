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

  ull A, K;
  cin >> A >> K;
  if (K == 0) {
    cout << 2000000000000 - A << endl;
    return 0;
  } else {
    int day = 0;
    while (true) {
      day++;
      A += 1 + A * K;
      if (A >= 2000000000000) {
        cout << day << endl;
        return 0;
      }
    }
  }
  return 0;
}
