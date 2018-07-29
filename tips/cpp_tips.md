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

- max_element returns a iterater, so you should add "*".

```
int min = *std::min_element(vec.begin(), vec.end());
int max = *std::max_element(vec.begin(), vec.end());
```
