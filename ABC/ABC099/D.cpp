
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdio>

using namespace std;

int main(){

  int n, C;

  cin >> n >> C;

  int D[C][C];
  //int c[n][n];
    int r;

  int auau;
  for (int i=0; i < C; i++){
    for(int j=0; j < C; j++){
      r = scanf("%d", &D[i][j]);
    }
  }
  int a[3][31] = {};

  for (int i=0; i < n; i++){
    for(int j=0; j < n; j++){
      r = scanf("%d", &auau);
      a[(i+j)%3][auau-1]++;
    }
  }
  // for(int i = 0; i < 3; i++){
  //   for (int j = 0; j < C; j++){
  //     cout << a[i][j];
  //   }
  //   cout << endl;
  // }
  long long res = 0;
  long long min_res = 999999999;
  for(int i=0; i < C; i++){
    for (int j = 0; j< C; j++){
      for (int k = 0; k < C; k++){
        if((i != j) && (j != k) && (i != k)){
          res = 0;
          for (int l = 0; l < C; l++){
            res += (a[0][l] * D[l][i] + a[1][l] * D[l][j] + a[2][l] * D[l][k]);
          }
          //cout << res << endl;
          min_res = min(min_res, res);
        }
      }
    }
  }

  cout << min_res << endl;


  return 0;

}
