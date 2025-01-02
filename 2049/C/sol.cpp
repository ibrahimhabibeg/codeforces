#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
  int n, x, y;
  scanf("%d%d%d", &n, &x, &y);
  x--;
  y--;
  int a[n];
  a[0] = 0;
  for (int i = 1; i < n; i++) {
    vector<bool> b(3);
    b[a[i-1]] = true;
    if(i==y) b[a[x]] = true;
    if(i==n-1) b[a[0]] = true;
    if(!b[0]) a[i] = 0;
    else if(!b[1]) a[i] = 1;
    else if(!b[2]) a[i] = 2;
    else a[i] = 3;
  }
  for (int i = 0; i < n; i++) printf("%d ", a[i]);
  printf("\n");
}

int main(){
  int TC;
  scanf("%d", &TC);
  while(TC--){
    solve();
  }
}