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

  bool isable = true;

  int i = 0;

  int state = 0;
  while (i < array.size()){
    if (state == 0){
      if (array.substr(i, 5) == "dream"){
        state = 1;
        i += 5;
      }else if(array.substr(i, 5) == "erase"){
        state = 3;
        i += 5;
      }else {isable = false; break;}
    }else if (state == 1){
      if (array.substr(i, 5) == "dream"){
        state = 1;
        i += 5;
      } else if(array.substr(i, 2) == "er"){
        state = 2;
        i += 2;
      }else {isable = false; break;}
    }else if (state == 2){
      if (array.substr(i, 5) == "dream"){
        state = 1;
        i += 5;
      }else if(array.substr(i, 5) == "erase"){
        state = 3;
        i += 5;
      }else if(array.substr(i, 3) == "ase"){
        state = 3;
        i += 3;
      }else {isable = false; break;}
    }else if (state == 3){
      if (array.substr(i, 5) == "dream"){
        state = 1;
        i += 5;
      }else if(array.substr(i, 5) == "erase"){
        state = 3;
        i += 5;
      }else if(array.substr(i, 1) == "r"){
        state = 0;
        i += 1;
      }else {isable = false; break;}
    }else {isable = false; break;}

  }

  if (isable){
    cout << "YES" << endl;
  }else{
    cout << "NO" << endl;
  }

  return 0;

}
