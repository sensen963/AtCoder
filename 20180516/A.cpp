#include <iostream>


using namespace std;
int main(){

  int A;
  int B;
  cin >> A >> B;

  int max;
  if (A + B < A - B){
    max = A - B;
  }else{
    max = A + B;
  }

  if (max < A * B){
    max = A * B;
  }
  cout << max;

  return 0;
}
