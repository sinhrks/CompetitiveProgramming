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

    pair<int, int> points[100];

    for (int i = 0; i < N; i++) {
      int x, y;
      cin >> x >> y;
      points[i] = make_pair(x, y);
    }

    int d = -1;

    for (int i = 0; i < N - 1; i++) {
      for (int j = i; j < N; j++) {
        pair<int, int> p1 = points[i];
        pair<int, int> p2 = points[j];

        int tmp = (p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second);
        d = max(tmp, d);
      }
    }

    printf("%.11f\n", sqrt((double)d));
    return 0;
}
