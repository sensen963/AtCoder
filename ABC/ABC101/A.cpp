#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdio>

using namespace std;

int main(){

  string array;

  cin >> array;
  int tmp = 0;
  for (int i = 0; i < 4; i++){
    if (array[i] == '+'){
      tmp++;
    }else{
      tmp--;
    }
  }
  cout << tmp << endl;


  return 0;

}
