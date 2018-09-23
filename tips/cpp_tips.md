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
