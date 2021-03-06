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

  if (S == "AKIHABARA" ||
      S == "KIHABARA" ||
      S == "AKIHBARA" ||
      S == "AKIHABRA" ||
      S == "AKIHABAR" ||
      S == "KIHBARA" ||
      S == "KIHABRA" ||
      S == "KIHABAR" ||
      S == "AKIHBRA" ||
      S == "AKIHBAR" ||
      S == "AKIHABR" ||
      S == "KIHBRA" ||
      S == "KIHBAR" ||
      S == "KIHABR" ||
      S == "AKIHBR" ||
      S == "KIHBR") {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
