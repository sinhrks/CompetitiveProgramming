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
    int N;
    cin >> N;

    uint64_t T[100] = {0};
    uint64_t c = 1;
    for (int i=0; i < N; i++) {
        cin >> T[i];
        c = c * (T[i] / __gcd(T[i], c));
    }

    cout << c << endl;
    return 0;
}
