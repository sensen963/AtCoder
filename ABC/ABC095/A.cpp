#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdio>

using namespace std;

int main(){

  string tmp;

  cin >> tmp;

  int pr = 700;

  for (int i = 0; i<3; i++) if(tmp[i] == 'o') pr += 100;

  cout << pr << endl;

  return 0;
}
