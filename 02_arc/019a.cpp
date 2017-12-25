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

  string S;
  cin >> S;
  REP(i, S.size()) {
    if (S[i] == 'O') S[i] = '0';
    if (S[i] == 'D') S[i] = '0';
    if (S[i] == 'I') S[i] = '1';
    if (S[i] == 'Z') S[i] = '2';
    if (S[i] == 'S') S[i] = '5';
    if (S[i] == 'B') S[i] = '8';
  }

  cout << S << endl;
  return 0;
}
