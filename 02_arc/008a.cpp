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

    int r = (N / 10) * 100;

    if (N % 10 >= 7) {
      r += 100;
    } else {
      r += (N % 10) * 15;
    }
    cout << r << endl;
    return 0;
}
