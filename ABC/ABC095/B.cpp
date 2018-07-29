#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdio>

using namespace std;

int main(){

  vector<int> w;
  int n, x;

  cin >> n >> x;

  int tmp;
  int sum = 0;
  int min_w = 999999;
  for (int i = 0; i < n; i++){
    cin >> tmp;
    w.push_back(tmp);
    sum += tmp;
    min_w = min(min_w, tmp);
  }

  x -= sum;
  n += x / min_w;

  cout << n << endl;
}
