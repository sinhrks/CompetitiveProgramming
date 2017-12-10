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
  int p[100010] = {};
  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> p[i];
  }

  int sp = 0;
  for (int i = 0; i < N; i++) {
    if (p[i] - 1 == i) {
      sp++;
      p[i + 1] = p[i];
    }
  }

  cout << sp << endl;
  return 0;
}
