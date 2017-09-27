#include <assert.h>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
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

  int a[100010] = {};
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }

  int l = 1;
  int r = 1;
  int total = 0;

  int current = a[0];
  while (l <= N) {
    while (current < a[r + 1]) {
      current = a[r + 1];
      r++;
    }
    total += (r - l + 1);
    l++;
  }
  cout << total << endl;
  return 0;
}
