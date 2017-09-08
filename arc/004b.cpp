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

    int ma = 0;
    int total = 0;
    for (int i = 0; i < N; i++) {
      int c;
      cin >> c;
      ma = max(ma, c);
      total += c;
    }

    cout << total << endl;
    if (total - ma >= ma) {
      cout << 0 << endl;
    } else {
      cout << 2 * ma - total << endl;
    }
    return 0;
}
