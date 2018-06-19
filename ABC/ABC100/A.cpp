#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdio>

using namespace std;

int main(){
  int a, b;

  cin >> a >> b;

  if (a <= 8 && b <= 8){
    cout << "Yay!" << endl;
  }else{
    cout << ":(" << endl;
  }

  return 0;
}
