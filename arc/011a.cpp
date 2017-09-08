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

    int m, n, N;
    cin >> m >> n >> N;

    int sold = N;
    int current = N;

    while (current >= m) {;
      int r = (current / m) * n;
      sold += r;
      current = current % m + r;
    }

    cout << sold << endl;
    return 0;
}
