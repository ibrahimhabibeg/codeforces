#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
  int x, y, a;
  scanf("%d%d%d", &x, &y, &a);
  if(a%(x+y)<x) printf("NO\n");
  else printf("YES\n");
}

int main(){
  int TC;
  scanf("%d", &TC);
  while(TC--){
    solve();
  }
}