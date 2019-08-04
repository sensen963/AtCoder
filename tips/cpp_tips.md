# About

i will write dowm C++ tips for competitive programming here.

# Tips

## Sum of vector

```

std::accumulate(vect.begin(), vect.end(), 0)

```

- first argument is the iterater of vector's begin
- second is vector's end
- third is initial
- when dealing big numbers, use `0LL` as initial because of overflow

### multiply

- when using multiply,

```
std::accumulate(vect.begin(), vect.end(), 1, Multiply())

```

## Max and min of vector

- max_element returns a iterator, so you should add *.


```

int min = *std::min_element(vec.begin(), vec.end());
int max = *std::max_element(vec.begin(), vec.end());

```

## map

- associative containers that store elements formed by a combination of a key value and a mapped value,

- key and value use pair type
- so the element of map refers like below

```
std::map<int, int> mp;

for (auto iter = mp.begin(); iter != mp.end(); iter++){
  cout << "key:" << iter->first << endl;
  cout << "value:" << iter->second << endl;
}

```

## Combination(n, m) mod p

- when calculating combination, the overflow occurs because n and m are enormous.
- so needed the mod of combination.
- [nCr mod m の求め方](https://ikatakos.com/pot/programming_algorithm/number_theory/mod_combination)

```

ll MOD = pow(10, 9) + 7

ll powmod(ll a, ll p, ll MOD) {
	ll ans = 1;
	ll mul = a;
	for (; p > 0; p >>= 1, mul = (mul * mul) % MOD) {
		if ((p & 1) == 1)ans = (ans * mul) % MOD;
	}
	return ans;
}

ll combmod(ll n, ll r, ll MOD){
  if(n < r) return 0LL;
  if (n < 0 || r < 0) return 0LL;
  vector<ll> ff(n+1), vff(n+1);
  // 1! ~ n!
  ff[0] = 1;
  for(ll i = 1; i < n + 1; i++) {
    ff[i] = ff[i - 1] * i % MOD;
  }
  // n!^(MOD-2) (= n!^(-1))
  ll inv = powmod(ff[n], MOD - 2, MOD);

  // n!^(-1) ~ 1!^(-1)
  vff[n] = inv;
  for(ll i = n - 1; i >= 0; i--) {
    vff[i] = vff[i + 1] * (i + 1) % MOD;
  }

  // n combination r
  ll comb = (((ff[n] * vff[r]) % MOD) * vff[n - r]) % MOD;

  return comb;
}

```

## sort

- when sorting vector type, (ascending order)

```


#include <vector>
#include <algorithm>
#include <functional>

std::sort(v.begin(), v.end())

```

- if descending order,

```

std::sort(v.begin(), v.end(), std::greater<long long>())

```
- when argsort or as a key
  - using lambda

```

vector<pair<ll, ll>> A(N);
REP(i, N) cin >> A[i].first >> A[i].second;

sort(A.begin(), A.end(), [](pair<ll, ll> x, pair<ll, ll> y) { return x.first < y.first;});

```

- can use struct type

```
struct hoge{
  int x;
};

vector<hoge> A(N);
REP(i, N) cin >> A[i].x;

sort(A.begin(), A.end(), [](hoge& x, hoge& y) {
  return x.first < y.first;
  });

```

## Union Find

- int 

```

struct UnionFind {
    vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2
    vector<int> _size; // 属する連結成分の大きさ

    UnionFind(int N) : par(N), _size(N) { //最初は全てが根であるとして初期化
        for(int i = 0; i < N; i++) {
            par[i] = i;
            _size[i] = 1;
        }
    }

    int root(int x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y) { // xとyの木を併合
        int rx = root(x); //xの根をrx
        int ry = root(y); //yの根をry
        if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま
        par[rx] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
        _size[ry] += _size[rx];
    }

    bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }

    int size(int x){
        int rx = root(x);
        return _size[rx];
    }
};

```

- ll

```
struct UnionFind {
    vector<ll> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2
    vector<ll> _size; // 属する連結成分の大きさ

    UnionFind(ll N) : par(N), _size(N) { //最初は全てが根であるとして初期化
        for(ll i = 0; i < N; i++) {
            par[i] = i;
            _size[i] = 1;
        }
    }

    ll root(ll x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(ll x, ll y) { // xとyの木を併合
        ll rx = root(x); //xの根をrx
        ll ry = root(y); //yの根をry
        if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま
        par[rx] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
        _size[ry] += _size[rx];
    }

    bool same(ll x, ll y) { // 2つのデータx, yが属する木が同じならtrueを返す
        ll rx = root(x);
        ll ry = root(y);
        return rx == ry;
    }

    ll size(ll x){
        ll rx = root(x);
        return _size[rx];
    }
};

```