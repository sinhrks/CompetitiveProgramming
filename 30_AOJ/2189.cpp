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

# define INF 0x3f3f3f3f

#define REP(i, n) for (int i = 0; i < n; i++)
#define REPR(i, n) for (int i = n; i >= 0; i--)
#define DEBUG(vec) for (auto v : vec) { cout << v << " "; } cout << endl;

using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;

  REP(x, N) {
    string S;
    cin >> S;

    int digits = S.size();
    int total = 0;
    REP(i, digits) {
      total += S[i] - '0';
    }
    if ((digits + (total - 1) / 9) % 2 == 0) {
      cout << "Fabre wins." << endl;
    } else {
      cout << "Audrey wins." << endl;
    }
  }
  return 0;
}
