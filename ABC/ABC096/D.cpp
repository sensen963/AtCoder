#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main(){

  int n;
  cin >> n;

  vector<int> data;

  int i = 11;
  int tmp = 2;
  bool ismod = false;
  while(data.size() != n){
    ismod = false;
    tmp = int(sqrt(i));
    for (int j = 2; j <= tmp; j++){
      if (i % j == 0){
        ismod = true;
        break;
      }
    }
    if (!ismod){
      data.push_back(i);
    }
    i += 10;
  }
  for (int j; j < n; j++){
    cout << data[j] << " ";
  }
  cout << endl;

  return 0;
}
