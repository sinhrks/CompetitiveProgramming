#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <string>
#include <vector>
typedef long long ll;

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    string s;
    cin >> s;

    int total = 0;

    for (int i = 0; i < N; i++) {
      if (s[i] == 'A') {
        total += 4;
      } else if (s[i] == 'B') {
        total += 3;
      } else if (s[i] == 'C') {
        total += 2;
      } else if (s[i] == 'D') {
        total += 1;
      }
    }

    printf("%.11f", (double)total / N);
    return 0;
}
