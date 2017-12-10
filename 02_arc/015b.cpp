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

  int N;
  cin >> N;

  int mo = 0, man = 0, na = 0, ne = 0, fu = 0, maf = 0;

  for (int i = 0; i < N; i++) {
    float ma, mi;
    cin >> ma >> mi;
    if (ma >= 35.0) {
      mo++;
    } else if (ma >= 30) {
      man++;
    } else if (ma >= 25) {
      na++;
    }
    if (mi >= 25) {
      ne++;
    }
    if (ma >= 0 && mi < 0) {
      fu++;
    } else if (ma < 0) {
      maf++;
    }
  }


  cout << mo << " " << man << " " << na << " " << ne << " " << fu << " " << maf << endl;
  return 0;
}
