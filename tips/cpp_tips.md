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
