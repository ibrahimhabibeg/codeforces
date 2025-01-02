#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
  int n, p =0, s = 0;
  scanf("%d", &n);
  char t[n+1];
  scanf("%s", t);
  for (int i =0; i<n; i++) p+=t[i]=='p', s+=t[i]=='s';
  if(p==0 || s==0) printf("YES\n");
  else if(p==1 && t[n-1]=='p') printf("YES\n");
  else if(s==1 && t[0]=='s') printf("YES\n");
  else printf("NO\n");
}

int main(){
  int TC;
  scanf("%d", &TC);
  while(TC--){
    solve();
  }
}