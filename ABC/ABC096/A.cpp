#include <iostream>


using namespace std;
int main(){

  int a, b, c;

  cin >> a >> b;

  if (a <= b){
    c = a;
  }else{
    c = a - 1;
  }

  cout << c << endl;

  return 0;
}
