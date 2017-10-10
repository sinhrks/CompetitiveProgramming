#include <algorithm>
#include <numeric>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
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
typedef long long ll;

using namespace std;

// x^n
template<class val>
long pow_mod(val x, val n, val d) {
  val ans = 1;
  while (n > 0) {
    if ((n & 1) == 1) {
      ans = ans * x % d;
    }
    x = x * x % d;
    n >>= 1;
  }
  return ans;
}

// x^n
template<class val>
long pow(val x, val n) {
  val ans = 1;
  while (n > 0) {
    if ((n & 1) == 1) {
      ans = ans * x;
    }
    x = x * x;
    n >>= 1;
  }
  return ans;
}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll N, M, P;
    cin >> N >> M >> P;

    cout << pow_mod(N, P, M) << endl;
    return 0;
}
