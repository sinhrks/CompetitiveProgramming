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
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int start = max(a, c);
    int end = min(b, d);

    if (start < end) {
        cout << end - start << endl;
    } else {
        cout << 0 << endl;
    }
    return 0;
}
