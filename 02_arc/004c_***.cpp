#include <algorithm>
#include <numeric>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <functional>
#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <complex>
typedef long long ll;

using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll X, Y;
    scanf("%lld/%lld", &X, &Y);
    double N, M;
    for (int i = 0; i < 2; i++) {
      N = floor(1. * X / Y * 2.) + i;
      M = N * (N + 1.) / 2. - 1. * X / Y * N;
      if (floor(M) == M && 1. <= M && M <= N) {
        cout << (ll)N << " " << (ll)M << endl;
        return 0;
      }
    }
    cout << "Impossible" << endl;
    return 0;
}
