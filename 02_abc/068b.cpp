#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    for (int i = 6; i >= 0; i--) {
       int c = 1 << i;
       if (c <= N) {
          cout << c << endl;
          return 0;
       }
    }
    return 0;
}
