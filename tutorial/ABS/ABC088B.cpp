#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdio>

using namespace std;

int main(){

  int n, a;
  vector<int> array;
  cin >> n;
  for (int i = 0; i < n; i++){
    scanf("%d", &a);
    array.push_back(a);
  }

  sort(array.begin(), array.end(), greater<int>());

  int alice = 0;
  int bob = 0;
  for(int i = 0; i < n; i++){
    if(i % 2 == 0){
      alice += array[i];
    }else{
      bob += array[i];
    }
  }

  cout << alice - bob << endl;

  return 0;
}
