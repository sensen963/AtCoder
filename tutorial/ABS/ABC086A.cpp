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

  if ((a * b) % 2 == 0){
    cout << "Even" << endl;
  }else{
    cout << "Odd" << endl;
  }


  return 0;

}
