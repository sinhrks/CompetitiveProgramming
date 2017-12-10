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
#define DEBUG(vec) for (auto v : vec) { cout << v << " "; } cout << endl;

using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;
  int D = N % 10;
  N /= 10;
  int C = N % 10;
  N /= 10;
  int B = N % 10;
  N /= 10;
  int A = N % 10;

  if (A + B + C + D == 7) printf("%d+%d+%d+%d=7\n", A, B, C, D);
  else if (A - B + C + D == 7) printf("%d-%d+%d+%d=7\n", A, B, C, D);
  else if (A + B - C + D == 7) printf("%d+%d-%d+%d=7\n", A, B, C, D);
  else if (A - B - C + D == 7) printf("%d-%d-%d+%d=7\n", A, B, C, D);
  else if (A + B + C - D == 7) printf("%d+%d+%d-%d=7\n", A, B, C, D);
  else if (A - B + C - D == 7) printf("%d-%d+%d-%d=7\n", A, B, C, D);
  else if (A + B - C - D == 7) printf("%d+%d-%d-%d=7\n", A, B, C, D);
  else if (A - B - C - D == 7) printf("%d-%d-%d-%d=7\n", A, B, C, D);
  return 0;
}
