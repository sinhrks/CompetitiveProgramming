

# テンプレート

- [template.cpp](template.cpp)

# チェックリスト

- 入力フォーマットは確認したか (文字列か、空白区切か)
- 初期化
  - 配列は正しく初期化しているか
    - 全て 0 出ない場合はループを回す
    - 大きすぎる配列はグローバルに置く(スタックに置けない)
    - 配列の区切りにカンマを書く (要素が文字列で間に改行が入る場合、カンマが抜けてないか)
  - 変数は正しく初期化されているか
    - 条件付き初期化の場合のデフォルトに注意！
- 計算結果は正しいか
  - 式の途中で int / doubleの除算が混在し、意図しない結果になっていないか
  - 桁あふれしそうなところはないか
  - 負の値があり得るところに、unsignedを使っていないか
- ループの添え字は正しいか
  - 逆回しのループはできるだけ避ける。 `i--` になっているか確認する
- 更新式はシンプルか
  - 更新後の値で条件判定しなければならない場合は一時変数を使う
- 非正常処理 ("NO", "IMPOSSIBLE")は正しく考慮されているか
- 出力フォーマットは正しいか
  - 要求された精度で出力できているか
  - 末尾に改行がいるか
  - 一定の条件でフィルタして出力する際、出力の区切り(スペース、改行は正しいか)。先頭/末尾がフィルタされても正しく動くか

# 基本

- 論理演算 `and`, `or`, `not` を使う
- 三項演算 `cond ? true : false`
- `swap(a, b)`

# 数値

|型名|ビット数|範囲|下限|上限|
|:--:|:--:|:--:|:--:|:--:|
| `int` | 32 | -10^9 〜 10^9 | `INT_MIN` | `INT_MAX` |
| `int64_t` | 64 | -10^18 〜10^18 | `INT64_MIN` | `INT64_MAX` |
| `long long` | 64 | | | |
| `uint64_t` | 64 | | `UINT64_MIN` | `UINT64_MAX` |
| `double` | 64 | | | | |

- 桁が大きい場合、掛け算、割り算の順序によるオーバーフローに注意
- `min`, `max`, `abs`
- 切り上げ除算: `(a + b - 1) / b`
- 四捨五入: `(int)(a + 0.5)`
- キャスト: `(double)a / b`
- 誤差: 丸めの方向を考える
  ```
  const double EPS = 1e-10;
  a <= b + EPS
  a < b - EPS
  ```

- 円周率: `const double PI = acos(-1.0)`
- 最大公約数: `__gcd`
- 最小公倍数: `ab = gcd * lcm`
- 繰り返し2乗法 `x ^ n` [mathlib.cpp](src/mathlib.cpp)

# 入出力

呼び出しが1万回を超える場合は Cストリームを使う

## 入力

- フォーマット指定: `scanf("%d/%d/%d", &y, &m, &d)`
  - `scanf` と `cin` を混在させてはならない
  - 必ず AtCoder のコードテストで動作確認
- 空白を含む行の読み込み
```
// 直前まで cin を使っていた場合
cin.ignore();
string s;
getline(cin, s);
```

## 出力

- フォーマット指定`printf("%.10f\n", ans)`

# 実行時間の見積もり

## 目安

|実行時間($10^n$形式)|実行時間(一般形式)|実行時間制限に間に合うかどうか|
|:--:|:--:|:--:|
| O(10^6) | O(100万) |余裕で間に合う|
| O(10^7) | O(1,000万) |おそらく間に合う|
| O(10^8) | O(1億) |非常にシンプルな処理でない限り、間に合わない|

# 文字列 (`string`)

- 初期化時に値を入れる `string a("abc")`
- 文字列の長さ `str.size()`
- 検索 `str.find()`
  - `if (s.find(c) == std::string::npos) {`
- 文字列連結 `str1 + str2`
- (部分文字列) `str.substr(pos,len)``;
- 置換
  - 開始位置と長さを指定 `s.replace(9, 3, "xxx")`
  - 特定文字を置換: `std::replace(s.begin(), s.end(), 'a', 'b')`;
- (ASCIIコード)
  - ```for (char c='a'; c<='z'; c++) {```
- 変換: `to_string(i)`
- 配列を結合
  ```
  vector<string> ss; // 入力で受け取った string の配列
  string s = accumulate(ss.begin(), ss.end(), string());
  ```

# ビット演算

- 使える場合は `bitset` を使う
- シフト 左: `<<`, 右: `>>`
  - これが入るときはカッコをつけて計算順序を保証
- 立っているビットの個数を数える: `__builtin_popcount`
- Leading Zeroを数える: `__builtin_clz`
- Trailing Zeroを数える: `__builtin_ctz`
- プリントデバッグ
  ```
  template<class val>
  void print_binary(val x, int width) {
    cout << x << endl;
    val bit = (1 << (width - 1));
    for (int i = 0; i < width; i++) {
      if (x & bit)
        putchar('1');
      else
        putchar('0');
      bit >>= 1;
    }
    printf("\n");
  }
  ```

- 回転シフト [bitlib.cpp](src/bitlib.cpp)

# 配列

- 初期化
  - ゼロ初期化: `int a[3] = {}`
  - `int a[3] = {100}` はダメ。
  - 配列は必ず初期化する
- 数え上げ: `count(f, t, x)`
  - 変数名に `count`を使わないこと！
- 初期化: `fill(f, t, x)`

- `vector`
  - `vector<int> a(N, 0)` は長さ N を要素 0 で初期化 (書き換え前提)
  - `vector<int> a` なら長さ 0 で初期化 (`push_back` 前提)

- 配列の合計
  ```
  accumulate(a.begin(), a.end(), 0LL )
  ```
- 最大、最小
  ```
  int ma = *max_element(a, a + N);
  int mi = *min_element(a, a + N);
  ```
- 出力
  ```
  REP(i, a.size) {
    cout << a[i] << endl;
  }
  ```

- 逆順
  ```
  REPR(i, a.size) {
    cout << a[i] << endl;
  }
  ```

- 相互変換
  ```
  // set -> vector
  vector<int> vec(s.begin(), s.end());

  // vector -> set
  set<int> s2(vec.begin(), vec.end());
  ```

# ソート、順序変更

- 昇順: `sort(arr, arr + N)`
- 降順: `sort(arr, arr + N, greater<int>())`
- `stable_sort`
- 逆転: `reverse`
- 順列生成
  ```
  sort(v.begin(), v.end());
  do {
    for(auto x : v) cout << x << " "; cout << "\n";
  } while (next_permutation(v.begin(), v.end()));
  ```

# 連想配列

- key と value を入れ替え [containerlib.cpp](src/containerlib.cpp)
- カウンター [containerlib.cpp](src/containerlib.cpp)

# アルゴリズム

- grundy数
- BFS, DFS
  ```
  // 右、下、左、上
  const int dx[4] = {1, 0, -1, 0};
  const int dy[4] = {0, 1, 0, -1};

  class Point {
   public:
    int x;
    int y;

    Point(int xx, int yy) {
      x = xx;
      y = yy;
    }
  };

  struct Searcher2D {
    int W, H;
    vector<vector<bool>> visited;
    explicit Searcher2D(int width, int height) {
      W = width;
      H = height;
      visited = vector<vector<bool>>(H, vector<bool>(W, false));
    }
    int search(int x, int y) {
      // stack<Point> container;   // DFS
      queue<Point> container;      // BFS
      container.push(Point(x, y));

      while (!container.empty()) {
        // Point p = container.top();     // DFS
        Point p = container.front();      // BFS
        container.pop();

        for (int i = 0; i < 4; i++) {
          int nx = p.x + dx[i];
          int ny = p.y + dy[i];
          if (nx >= 0 && nx < W && ny >= 0 && ny < H) {
            if (!visited[ny][nx]) {

              // 適当な処理を追加

              container.push(Point(nx, ny));
            }
          }
        }
        visited[p.y][p.x] = true;
      }
      return 0;
    }
  };
  ```
- メモ化再帰
- 動的計画法（DP）（確率DP，ビットDPを含む）
- 累積和 [containerlib.cpp](src/containerlib.cpp)
- いもす法
  ```
  for (int i = 0; i < T; i++) table[i] = 0;
  for (int i = 0; i < C; i++) {
      table[S[i]]++;  // 入店処理: カウントを 1 増やす
      table[E[i]]--;  // 出店処理: カウントを 1 減らす
  }
  // シミュレート
  for (int i = 0; i < T; i++) {
      if (0 < i) table[i] += table[i - 1];
  }
  // 最大値を調べる
  M = 0;
  for (int i = 0; i < T; i++) {
      if (M < table[i]) M = table[i];
  }
  ```
- しゃくとり法
- 二分探索 (最小値、最大値)
  - `lower_bound(a.begin(), a.end(), k)` k以上の値が初めて現れる位置へのイテレータ
  - `upper_bound(a.begin(), a.end(), k)` kより大きい値が初めて現れる位置へのイテレータ
    - 位置を取りたい場合は `it - a.begin()`
    - ある値の個数 `lower_bound(a.begin(), a.end(), k) - upper_bound(a.begin(), a.end(), k)`

  ```
  ll binary_search(ll low, ll high, std::function<bool(ll)> check){
    if(high-low==1){
      return low;
    }
    ll mid = (high+low)/2;
    if(check(mid)){
      return binary_search(mid, high, check);
    }else{
      return binary_search(low, mid, check);
    }
  }
  ```

  ```
  while (right - left > 1) {
    ll trial = (left + right) / 2;
    ...
    if (...) {
      right = trial;
    } else {
      left = trial;
    }
  }
  ```

- 三分探索
- 階乗のmod逆元
- ダブリング（数列）
- Union-Find木 [graphlib.cpp](src/graphlib.cpp)
- セグメント木（遅延評価なし）
  ```
  template <typename T>
  struct SegTree {
    // 要素数に対して必要な2進数の桁数を指定
    int N;
    vector<T> data;
    // 初期化に使う値を定義 (要変更)
    int init = 0;

    explicit SegTree(int n_) {
      N = 1;
      while (N < n_) {
        N *= 2;
      }
      data = vector<T>(2 * N - 1, init);
    }
    // 二つの区間の更新規則を定義 (要変更)
    T update_rule(T v1, T v2) {
      return v1 + v2;
    }
    void update(int i, T val) {
      i += N - 1;
      data[i] = val;
      while (i > 0) {
        i = (i - 1) / 2;
        data[i] = update_rule(data[i * 2 + 1], data[i * 2 + 2]);
      }
    }
    T query(T a, T b) {
      return internal_query(a, b, 0, 0, N);
    }
    T internal_query(T a, T b, int k, int l, int r) {
      if (r <= a || b <= l) return init;
      if (a <= l && r <= b) {
        return data[k];
      } else {
        int vl = internal_query(a, b, k * 2 + 1, l, (l + r) / 2);
        int vr = internal_query(a, b, k * 2 + 2, (l + r) / 2, r);
        return update_rule(vl, vr);
      }
    }
  };
  ```
- BIT
  ```
  template <typename T>
  struct BIT {
    int N;
    vector<T> data;

    explicit BIT(int n_) {
      N = 1;
      while (N < n_) {
        N *= 2;
      }
      data = vector<T>(N, 0);
    }
    T sum(T i) {
      T s = 0;
      while (i > 0) {
        s += data[i];
        i -= i & -i;
      }
      return s;
    }
    void add(int i, T val) {
      while (i <= N) {
        data[i] += val;
        i += i & -i;
      }
    }
    // 指定された値以上の要素が最初に現れる位置を返す
    T lower_bound(T val) {
      T tv = 0;
      int ent = 0;
      for (int i = __builtin_ctz(N); i >= 0; i--) {
        if (tv + data[ent + (1 << i)] < val) {
          tv += data[ent + (1 << i)];
          ent += (1 << i);
        }
      }
      if (tv < val) {
        ent++;
      }
      return ent;
    }
  };
  ```

# STL(標準テンプレートライブラリ)

- [`array`](http://en.cppreference.com/w/cpp/container/array)
- [`vector`](http://en.cppreference.com/w/cpp/container/vector)
- [`queue`](http://en.cppreference.com/w/cpp/container/queue)
- [`stack`](http://en.cppreference.com/w/cpp/container/stack)
- [`deque`](http://en.cppreference.com/w/cpp/container/deque)
- [`priority_queue`](http://en.cppreference.com/w/cpp/container/priority_queue)
- [`list`](http://en.cppreference.com/w/cpp/container/list)
- [`set`](http://en.cppreference.com/w/cpp/container/set)
- [`map`](http://en.cppreference.com/w/cpp/container/map)
- [`string`](http://en.cppreference.com/w/cpp/string/basic_string)

# 場合の数

- 場合の数 [mathlib.cpp](src/mathlib.cpp)
- 完全順列

```
template <typename T>
T derangement(T N) {
  if (N <= 1) {
    return 0;
  } else if (N == 2) {
    return 1;
  }
  T p2 = 0, p1 = 1;
  for (T i = 3; i <= N; i++) {
    T n = (i - 1) * (p1 + p2);
    p2 = p1;
    p1 = n;
  }
  return p1;
}
```

# 日時

- [datetimelib.cpp](src/datetimelib.cpp)

# 座標平面

```
// 右、下、左、上
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

// 右、右下、下、左下、左、左上、上、右上
int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
 int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
```

斜めを含む場合、横方向と縦方向を分けて管理した方が良い場合もある

# グラフ

- 最短経路(ダイクストラ法) [graphlib.cpp](src/graphlib.cpp)
- 全点対間最小路 (Floyd Warshall)  [graphlib.cpp](src/graphlib.cpp)
- 最小全域木(クラスカル法) [graphlib.cpp](src/graphlib.cpp)
- 最大流(Dinic法) [graphlib.cpp](src/graphlib.cpp)

# 平面幾何

```
using namespace std;

const double EPS = 1e-8;
// const double INF = 1e12;

typedef complex<double> Point;

namespace std {
  bool operator < (const Point& a, const Point& b) {
    return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
  }
}

// 内積
double dot(const Point& a, const Point& b) {
  return real(conj(a) * b);
}

// 外積
double cross(const Point& a, const Point& b) {
  return imag(conj(a) * b);
}

// 直線、線分
struct Line : public vector<Point> {
  Line(const Point &a, const Point &b) {
    push_back(a);
    push_back(b);
  }
};

// 単純多角形 (反時計回り)
typedef vector<Point> Polygon;

// 円
struct Circle {
  Point p;
  double r;
  Circle(const Point &p, double r) : p(p), r(r) { }
};

// Counter Clockwise
int ccw(Point a, Point b, Point c) {
  b -= a;
  c -= a;
  if (cross(b, c) > 0)   return +1;       // counter clockwise
  if (cross(b, c) < 0)   return -1;       // clockwise
  if (dot(b, c) < 0)     return +2;       // c--a--b on line
  if (norm(b) < norm(c)) return -2;       // a--b--c on line
  return 0;
}

// 直線と直線が交差するか
bool intersectLL(const Line &l, const Line &m) {
  return abs(cross(l[1] - l[0], m[1] - m[0])) > EPS ||  // non-parallel
         abs(cross(l[1] - l[0], m[0] - l[0])) < EPS;    // same line
}

// 直線と線分が交差するか
bool intersectLS(const Line &l, const Line &s) {
  return cross(l[1] - l[0], s[0] - l[0]) *        // s[0] is left of l
         cross(l[1] - l[0], s[1] - l[0]) < EPS;   // s[1] is right of l
}

// 直線と点が交差するか
bool intersectLP(const Line &l, const Point &p) {
  return abs(cross(l[1] - p, l[0] - p)) < EPS;
}

// 線分と線分が交差するか
bool intersectSS(const Line &s, const Line &t) {
  return ccw(s[0], s[1], t[0]) * ccw(s[0], s[1], t[1]) <= 0 &&
         ccw(t[0], t[1], s[0]) * ccw(t[0], t[1], s[1]) <= 0;
}

// 線分と点が交差するか
bool intersectSP(const Line &s, const Point &p) {
  // triangle inequality
  return abs(s[0] - p) + abs(s[1] - p) - abs(s[1] - s[0]) < EPS;
}

// 点の直線への射影
Point projection(const Line &l, const Point &p) {
  double t = dot(p - l[0], l[0] - l[1]) / norm(l[0] - l[1]);
  return l[0] + t * (l[0] - l[1]);
}

// 点の直線に対する反射点
Point reflection(const Line &l, const Point &p) {
  return p + 2.0 * (projection(l, p) - p);
}

// 直線と点の距離
double distanceLP(const Line &l, const Point &p) {
  return abs(p - projection(l, p));
}

// 直線と直線の距離
double distanceLL(const Line &l, const Line &m) {
  return intersectLL(l, m) ? 0 : distanceLP(l, m[0]);
}

// 直線と線分の距離
double distanceLS(const Line &l, const Line &s) {
  if (intersectLS(l, s)) return 0;
  return min(distanceLP(l, s[0]), distanceLP(l, s[1]));
}

// 線分と点の距離
double distanceSP(const Line &s, const Point &p) {
  const Point r = projection(s, p);
  if (intersectSP(s, r)) return abs(r - p);
  return min(abs(s[0] - p), abs(s[1] - p));
}

// 線分と線分の距離
double distanceSS(const Line &s, const Line &t) {
  if (intersectSS(s, t)) return 0;
  return min(min(distanceSP(s, t[0]), distanceSP(s, t[1])),
             min(distanceSP(t, s[0]), distanceSP(t, s[1])));
}

Point crosspoint(const Line &l, const Line &m) {
  double A = cross(l[1] - l[0], m[1] - m[0]);
  double B = cross(l[1] - l[0], l[1] - m[0]);
  if (abs(A) < EPS && abs(B) < EPS) return m[0];  // same line
  return m[0] + B / A * (m[1] - m[0]);
}

// 平面操作法 (線分)
struct event {
  double x;
  int type;
  Line seg;
  event(double x, int type, const Line& seg) :
    x(x), type(type), seg(seg) { }
  bool operator < (const event &e) const {
    return x != e.x ? x > e.x : type > e.type;
  }
};

int segment_intersects(const vector<Line>& segs) {
  priority_queue<event> Q;
  for (int i = 0; i < segs.size(); ++i) {
    double x1 = real(segs[i][0]), x2 = real(segs[i][1]);
    Q.push(event(min(x1, x2), 0, segs[i]));
    Q.push(event(max(x1, x2), 1, segs[i]));
  }
  int count = 0;
  set<Line> T;
  while (!Q.empty()) {
    event e = Q.top(); Q.pop();
    if (e.type == 0) {
      for (set<Line>::iterator itr = T.begin();
          itr != T.end(); ++itr)
        if (intersectLS(*itr, e.seg)) {
          // *out++ = crosspoint(*itr, e.seg);
          ++count;
        }
      T.insert(e.seg);
    } else {
      T.erase(e.seg);
    }
  }
  return count;
}
```
