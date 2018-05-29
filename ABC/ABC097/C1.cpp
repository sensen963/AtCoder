#include <iostream>

using namespace std;

int main(){
  int N;
  cin >> N;
  char S[N];
  cin >> S;

  int count = 0;
  int sum_e[N];
  for (int i = 0; i < N; i++){
    if (S[i] == 'E'){
      count++;
    }
    sum_e[i] = count;
    //cout << sum_e[i] << endl;
  }
  int min = N;
  int tmp;
  for (int i = 0; i < N; i++){
    if (i == 0){
      tmp = sum_e[N-1] - sum_e[i];
    }else if (i == N-1){
      tmp = i - sum_e[i-1];
    }else{
      tmp = sum_e[N-1] - sum_e[i] + i - sum_e[i-1];
    }
    //cout << tmp << endl;
    if (tmp < min) min = tmp;
  }
  cout << min << endl;
  return 0;
}
