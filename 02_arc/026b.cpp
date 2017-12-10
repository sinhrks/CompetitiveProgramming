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

  ll N;
  cin >> N;
  
  ll t = 1;
  if (N == 1) {
    t = 0;
  }
  for (int i = 2; i < sqrt(N); i++) {
    if (N % i == 0) {
      t += i;
      t += N / i;
    }
  }
  if (t == N) {
    cout << "Perfect" << endl;
  } else if (t > N) {
    cout << "Abundant" << endl;
  } else {
    cout << "Deficient" << endl;
  }
  return 0;
}
