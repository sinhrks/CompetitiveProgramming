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

  bool pressed[9] = {};

  int total = 0;
  for (int i = 0; i < N; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < 9; j++) {
      if (s[j] == 'x') {
        total++;
        pressed[j] = false;
      } else if (s[j] == 'o') {
        if (!pressed[j]) {
          total++;
        }
        pressed[j] = true;
      } else {
        pressed[j] = false;
      }
    }
  }

  cout << total << endl;
  return 0;
}
