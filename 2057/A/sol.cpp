#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
  int n, m;
  scanf("%d%d", &n, &m);
  printf("%d\n", 1 + max(n, m));
}

int main(){
  int TC;
  scanf("%d", &TC);
  while(TC--){
    solve();
  }
}