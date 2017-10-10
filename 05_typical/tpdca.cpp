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

  int P[101] = {};
  for (int i = 0; i < N; i++) {
    cin >> P[i];
  }

  const int mscore = 10100;
  bool scores[10100] = {};
  scores[0] = true;
  for (int i = 0; i < N; i++) {
    for (int j = mscore - 1; j >= 0; j--) {
      if (scores[j]) {
        scores[j + P[i]] = true;
      }
    }
  }
  int total = accumulate(scores, scores + mscore, 0);
  cout << total << endl;
  return 0;
}
