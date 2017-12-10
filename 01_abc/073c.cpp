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

  set<int> s;
  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    if (s.find(a) != s.end()) {
      s.erase(a);
    } else {
      s.insert(a);
    }
  }

  cout << s.size() << endl;
  return 0;
}
