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

  int Deg, Dis;
  cin >> Deg >> Dis;
  Deg = Deg * 10;
  int win = (int)(Dis / 6.0 + 0.5);

  if (win <= 2) cout << "C";
  else if (1125 <= Deg && Deg < 3375) cout << "NNE";
  else if (Deg < 5625) cout << "NE";
  else if (Deg < 7875) cout << "ENE";
  else if (Deg < 10125) cout << "E";
  else if (Deg < 12375) cout << "ESE";
  else if (Deg < 14625) cout << "SE";
  else if (Deg < 16875) cout << "SSE";
  else if (Deg < 19125) cout << "S";
  else if (Deg < 21375) cout << "SSW";
  else if (Deg < 23625) cout << "SW";
  else if (Deg < 25875) cout << "WSW";
  else if (Deg < 28125) cout << "W";
  else if (Deg < 30375) cout << "WNW";
  else if (Deg < 32625) cout << "NW";
  else if (Deg < 34875) cout << "NNW";
  else cout << "N";

  cout << " ";

  if (win <= 2) cout << 0;
  else if (win <= 15) cout << 1;
  else if (win <= 33) cout << 2;
  else if (win <= 54) cout << 3;
  else if (win <= 79) cout << 4;
  else if (win <= 107) cout << 5;
  else if (win <= 138) cout << 6;
  else if (win <= 171) cout << 7;
  else if (win <= 207) cout << 8;
  else if (win <= 244) cout << 9;
  else if (win <= 284) cout << 10;
  else if (win <= 326) cout << 11;
  else cout << 12;

  cout << endl;
  return 0;
}
