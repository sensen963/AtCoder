#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdio>

using namespace std;

int main(){

  int d, n;

  cin >> d >> n;

  if (n != 100){
    cout << n * pow(100, d) << endl;;
  }else{
    cout << int(101 * pow(100, d)) << endl;
  }

  return 0;
}
