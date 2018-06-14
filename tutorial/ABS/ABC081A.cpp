#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdio>

using namespace std;

int main(){

  string a;
  cin >> a;

  int num = 0;

  for(int i=0; i < 3; i++){
    if (a[i] != '0') num++;
  }

  cout << num << endl;

  return 0;

}
