#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
  int n;
  scanf("%d", &n);
  string a, b;
  cin >> a >> b;
  int e = 0, o = 0;
  for (int i = 0; i < n; i++) {
    if(i%2 == 0 && a[i]=='0') e++;
    if(i%2 == 1 && a[i]=='0') o++;
  }
  for (int i = 0; i < n; i++) {
    if(i%2 == 0 && b[i]=='0') o++;
    if(i%2 == 1 && b[i]=='0') e++;
  }
  if(e>= (n+1)/2 && o>=n/2) printf("YES\n");
  else printf("NO\n");
}

int main(){
  int TC;
  scanf("%d", &TC);
  while(TC--){
    solve();
  }
}