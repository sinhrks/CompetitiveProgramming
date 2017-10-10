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
  string A, B;
  cin >> N >> A >> B;

  if (N == 1) {
    cout << 3 << endl;
    return 0;
  }

  ll pat = 0;
  bool cont;
  int i = 0;

  if (A[0] == B[0]) {
    pat = 3;
    i = 1;
    cont = false;
  } else {
    pat = 6;
    i = 2;
    cont = true;
  }

  for (; i < N; i++) {
    if (A[i] == B[i]) {
      if (cont) {
        pat *= 1;
      } else {
        pat *= 2;
      }
      cont = false;
    } else {
      if (cont) {
        pat *= 3;
      } else {
        pat *= 2;
      }
      i++;
      cont = true;
    }
    pat %= 1000000007;
  }

  cout << pat << endl;
  return 0;
}
