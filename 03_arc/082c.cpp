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
  int count[100001] = {};
  cin >> N;

  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    count[a]++;
  }

  int mx = 0;
  for (int i = 0; i < 100001 - 2; i++) {
    mx = max(mx, count[i] + count[i + 1] + count[i + 2]);
  }

  cout << mx << endl;
  return 0;
}
