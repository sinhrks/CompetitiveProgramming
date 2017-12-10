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

const int MX = 100010;
int A[MX] = {};


int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    A[a]++;
  }
  int ans = 0;
  for (int i = 0; i < MX; i++) {
    if (A[i] >= 1) {
      ans++;
    }
  }
  if (ans % 2 == 1) {
    cout << ans << endl;
  } else {
    cout << ans - 1 << endl;
  }
  return 0;
}
