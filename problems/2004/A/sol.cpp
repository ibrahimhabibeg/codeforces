#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
  int n;
  scanf("%d", &n);
  int a[n];
  for (int i = 0; i < n; i++){
    scanf("%d", &a[i]);
  }
  if(n > 2){
    printf("NO\n");
    return;
  }
  if(a[0] + 1 == a[1]){
    printf("NO\n");
  }else {
    printf("YES\n");
  }
}

int main(){
  int TC;
  scanf("%d", &TC);
  while(TC--){
    solve();
  }
}