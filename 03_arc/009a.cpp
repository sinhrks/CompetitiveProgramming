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

    int m = 0;
    for (int i = 0; i < N; i++) {
      int a, b;
      cin >> a >> b;
      m += a * b;
    }

    cout << int(floor(m * 1.05)) << endl;
    return 0;
}
