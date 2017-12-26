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

bool is_zoro(int n) {
  int z = n % 10;
  while (n > 0) {
    if (n % 10 != z) {
      return false;
    }
    n /= 10;
  }
  return true;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;

  int num = 0;
  for (int i = 1; ; i++) {
    if (is_zoro(i)) {
      num++;
      if (num == N) {
        cout << i << endl;
        return 0;
      }
    }
  }
  return 0;
}
