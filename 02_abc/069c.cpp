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

    int four = 0;
    int two = 0;
    int one = 0;
    for (int i=0; i<N; i++) {
        int temp;
        cin >> temp;
        if (temp % 4 == 0) {
          four++;
        } else if (temp % 2 == 0) {
          two++;
        } else {
          one++;
        }
    }
    cout << (four+1 >= (one + two % 2) ? "Yes" : "No");
    return 0;
}
