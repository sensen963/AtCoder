#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdio>

using namespace std;

int main(){

  int n;
  cin >> n;

  int r;

  vector<int> array;

  int inp;
  bool isin = false;
  r = scanf("%d", &inp);
  array.push_back(inp);

  for(int i = 1; i < n; i++){
    r = scanf("%d", &inp);

    for(int j = 0; j < array.size(); j++){
      if (inp == array[j]){
        isin = true;
        break;
      }
    }
    if(!isin) array.push_back(inp);
    isin = false;
  }

  cout << array.size() << endl;




  return 0;
}
