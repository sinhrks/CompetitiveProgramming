#include <assert.h>
#include <math.h>
#include <iostream>
#include <vector>

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

ll gcd(ll x, ll y) {
  while (y != 0) {
    ll r = x % y;
    x = y;
    y = r;
  }
  return x;
}

ll lcm(ll x, ll y) {
  return x * y / gcd(x, y);
}

template<class T>
bool is_prime(T n) {
  switch (n) {
    case 0: return false;
    case 1: return false;
    case 2: return true;
    case 3: return true;
  }
  if (n % 2 == 0) return false;
  if (n % 3 == 0) return false;

  if (n % 6 != 1 && n % 6 != 5) return false;
  for (int i = 5; i * i <= n; i += 6) {
    if (n % i == 0) return false;
    if (n % (i + 2) == 0) return false;
  }
  return true;
}

template<class T>
vector<T> eratosthenes(T n) {
  // ある数が素数でない場合に true
  vector<bool> dp(n, false);
  dp[0] = true;
  dp[1] = true;
  vector<T> prime;
  for (int i = 2; i < n; i++) {
    if (dp[i]) continue;
    prime.push_back(i);
    for (int j = i * 2; j < n; j += i) {
      dp[j] = true;
    }
  }
  return prime;
}

// 素因数分解
vector<ll> get_primes(ll n) {
  vector<ll> result;

  for (ll i = 2; i <= sqrt(n); i++) {
    while ((n % i) == 0) {
      result.push_back(i);
      n /= i;
    }
  }
  if (n > sqrt(n)) {
    result.push_back(n);
  }
  return result;
}

template<class T>
ll pow(T x, T n) {
  ll ans = 1;
  while (n > 0) {
    if ((n & 1) == 1) {
      ans = ans * x;
    }
    x = x * x;
    n >>= 1;
  }
  return ans;
}

template <typename T>
ull comb(T n, T k) {
  assert(n >= k);
  ull r = 1;
  for (ull d = 1; d <= static_cast<ull>(k); ++d) {
    r *= n--;
    r /= d;
  }
  return r;
}

const ll MOD7 = 1000000007;

struct ModNum {
  ll n;
  ll m;

  explicit ModNum(ll n, ll m) {
    this->n = n % m;
    this->m = m;
  }
  void operator+=(const ll &rhs) {
    n += rhs % m;
    n %= m;
  }
  ModNum operator+(const ll &rhs) {
    return ModNum((n + rhs % m) % m, m);
  }
  void operator-=(const ll &rhs) {
    ll r = rhs % m;
    if (r >= n) {
      n -= (r - m);
    } else {
      n -= r;
    }
    n %= m;
  }
  ModNum operator-(const ll &rhs) {
    ll r = rhs % m;
    if (r >= n) {
      return ModNum((n - r + m) % m, m);
    } else {
      return ModNum((n - r) % m, m);
    }
  }
  void operator*=(const ll &rhs) {
    n *= rhs % m;
    n %= m;
  }
  ModNum operator*(const ll &rhs) {
    return ModNum(n * (rhs % m) % m, m);
  }
};

struct FactorialTable {
  vector<ll> fact;
  vector<ll> inv;
  ll n;
  ll m;

  explicit FactorialTable(ll n, ll m) {
    this->n = n;
    this->m = m;
    fact = vector<ll>(n + 1, 0);
    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
      fact[i] = fact[i - 1] * i % m;
    }
    inv = vector<ll>(n + 1, 0);

    for (int i = 0; i <= n; i++) {
      inv[i] = mod_pow(fact[i], m - 2);
    }
    /*
    inv[n] = mod_pow(fact[n], m - 2);
    for (int i = n - 1; i >= 0; i--) {
      inv[i] = inv[i + 1] * (i + 1) % m;
    }
    */
  }
  ll mod_pow(ll x, ll n) {
    ll ans = 1;
    while (n > 0) {
      if ((n & 1) == 1) ans = ans * x % m;
      x = x * x % m;
      n >>= 1;
    }
    return ans;
  }
  ll factorial(int n) {
    assert(this->n > n);
    return fact[n];
  }
  // 組み合わせ nCk
  ll comb(int n, int k) {
    assert(this->n > n);
    assert(n >= k);
    return fact[n] * inv[k] % m * inv[n - k] % m;
  }
  // 重複組み合わせ nHr = (n + r + 1)Cr
  // n 種類のものから重複を許して r 個選ぶ場合の数
  ll mcomb(int n, int k) {
    return comb(n + k - 1, k);
  }
};

void test_gcd_lcm() {
  assert(gcd(3, 2) == 1);
  assert(lcm(3, 2) == 6);

  assert(gcd(4, 2) == 2);
  assert(lcm(4, 2) == 4);

  assert(gcd(4, 12) == 4);
  assert(lcm(4, 12) == 12);

  assert(gcd(28, 21) == 7);
  assert(lcm(28, 21) == 84);
}

void test_prime() {
  assert(!is_prime(0));
  assert(!is_prime(1));
  assert(is_prime(2));
  assert(is_prime(3));
  assert(!is_prime(4));
  assert(is_prime(5));
  assert(!is_prime(6));
  assert(is_prime(7));
  assert(is_prime(19));
  assert(!is_prime(20));
  assert(!is_prime(21));
  assert(!is_prime(22));
  assert(is_prime(23));

  // https://oeis.org/A000040
  vector<int> primes = eratosthenes(272);
  vector<int> expected = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43,
                          47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103,
                          107, 109, 113, 127, 131, 137, 139, 149, 151, 157,
                          163, 167, 173, 179, 181, 191, 193, 197, 199, 211,
                          223, 227, 229, 233, 239, 241, 251, 257, 263, 269,
                          271};
  assert(primes == expected);
  for (auto e : expected) {
    assert(is_prime(e));
  }
}

void test_primes() {
  vector<ll> e1 = {2, 2, 3};
  assert(get_primes(12) == e1);
  vector<ll> e2 = {2, 2, 3, 3};
  assert(get_primes(36) == e2);
}

void test_pow() {
  assert(pow(2, 3) == 8);
  assert(pow(2, 0) == 1);
  assert(pow(3, 3) == 27);
}

void test_comb() {
  assert(comb(1, 0) == 1);
  assert(comb(1, 1) == 1);

  assert(comb(3, 0) == 1);
  assert(comb(3, 1) == 3);
  assert(comb(3, 2) == 3);

  assert(comb(5, 0) == 1);
  assert(comb(5, 2) == 10);
  assert(comb(5, 3) == 10);
  assert(comb(5, 4) == 5);

  assert(comb(10, 5) == 252);
}

void test_modnum() {
  ModNum n1(10, 7);
  assert(n1.n == 3);

  assert((n1 + 5).n == 1);
  assert((n1 + 10).n == 6);
  assert((n1 + 11).n == 0);
  assert((n1 + 12).n == 1);

  assert((n1 - 1).n == 2);
  assert((n1 - 3).n == 0);
  assert((n1 - 4).n == 6);
  assert((n1 - 7).n == 3);
  assert((n1 - 10).n == 0);

  assert((n1 * 2).n == 6);
  assert((n1 * 3).n == 2);
  assert((n1 * 10).n == 2);

  n1 += 10;
  assert(n1.n == 6 && n1.m == 7);
  n1 += 8;
  assert(n1.n == 0 && n1.m == 7);
  n1 += 2;
  assert(n1.n == 2 && n1.m == 7);

  n1 -= 3;
  assert(n1.n == 6 && n1.m == 7);
  n1 -= 10;
  assert(n1.n == 3 && n1.m == 7);
  n1 -= 11;
  assert(n1.n == 6 && n1.m == 7);

  n1 *= 2;
  assert(n1.n == 5 && n1.m == 7);
  n1 *= 9;
  assert(n1.n == 3 && n1.m == 7);
}

void test_factorial_table() {
  FactorialTable f1(11, MOD7);
  assert(f1.factorial(2) == 2);
  assert(f1.factorial(3) == 6);
  assert(f1.factorial(4) == 24);
  assert(f1.factorial(4) * f1.inv[2] % MOD7 == 12);

  assert(f1.comb(10, 2) == 45);
  assert(f1.comb(10, 3) == 120);
  assert(f1.comb(10, 10) == 1);

  FactorialTable f2(10, 7);
  assert(f2.factorial(2) == 2);
  assert(f2.factorial(3) == 6);
  assert(f2.factorial(4) == 3);

  assert(f2.factorial(4) * f2.inv[2] % 7 == 5);
  assert(f2.factorial(4) * f2.inv[2] % 7 * f2.inv[2] % 7 == 6);
  assert(f2.comb(4, 2) == 6);
  assert(f2.comb(4, 3) == 4);
  assert(f2.comb(4, 4) == 1);

  FactorialTable f3(10001, MOD7);
  // the same result as scipy.misc.comb(10000, x, 1) % MOD7
  assert(f3.comb(10, 2) == 45);
  assert(f3.comb(10, 3) == 120);
  assert(f3.comb(10000, 1) == 10000);
  assert(f3.comb(10000, 2) == 49995000);
  assert(f3.comb(10000, 10) == 814128327);
  assert(f3.comb(10000, 100) == 138648429);
  assert(f3.comb(10000, 1000) == 155349879);
  assert(f3.comb(10000, 10000) == 1);

  // 重複組み合わせ
  assert(f3.mcomb(3, 4) == 15);
  assert(f3.mcomb(5, 2) == 15);
}

int main() {
  test_gcd_lcm();
  test_prime();
  test_primes();
  test_pow();
  test_comb();
  test_modnum();
  test_factorial_table();

  cout << "SUCCESS!!" << endl;
  return 0;
}
