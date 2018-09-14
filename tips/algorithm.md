# about

i will write dowm when using algorithms.

## algorithm

### expmod

- when calculating a^b mod p (p is prime)
- b is enomous so a^b becomes overflow or timeout
- with using [Fermat's little theorem](https://ja.wikipedia.org/wiki/%E3%83%95%E3%82%A7%E3%83%AB%E3%83%9E%E3%83%BC%E3%81%AE%E5%B0%8F%E5%AE%9A%E7%90%86), you can solve
- https://www.slideshare.net/chokudai/abc034

```
long long expmod(long long a, long long b, long long p) {
  if (b == 0) return 1;
  else if (b % 2 == 0) {
    long long d = expmod(a, b / 2, p);
    return (d * d) % p;
  } else if (b % 2 == 1) {
    return (a * expmod(a, b - 1, p)) % p;
  }
}

```
