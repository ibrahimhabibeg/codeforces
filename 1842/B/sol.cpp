#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n, x;
  cin >> TC;
  while (TC--){
    scanf("%d %d", &n, &x);
    int a[3][n];
    for (int i = 0; i < 3; i++) for (int j = 0; j < n; j++) scanf("%d", &a[i][j]); 
    int k = 0;
    for (int i = 0; i < 3; i++){
      int j = 0;
      while (j<n && ((a[i][j]&(~x))==0)) k|=a[i][j], j++;
    }
    if(k==x) printf("Yes\n");
    else printf("No\n");
  }   
}