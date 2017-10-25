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

using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  string A;
  cin >> A;

  if (A.size() == 1) {
    cout << 0 << endl;
  } else {
    ll total = 0;
    int diff = 0;
    for (int i = 0; i < A.size() / 2; i++) {
      if (A[i] != A[A.size() - 1 - i]) {
        diff++;
      }
    }
    // cout << diff << endl;
    if (diff != 1) {
      total = A.size() / 2 * 2 * 25;
    } else {
      total = ((A.size() / 2) - 1) * 2 * 25;
      total += 48;
    }
    if (diff != 0 && A.size() % 2 == 1) {
      total += 25;
    }
    cout << total << endl;
  }

  return 0;
}
