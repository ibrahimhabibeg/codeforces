#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n;
  cin >> TC;
  while (TC--){
    scanf("%d", &n);
    char s[n+1];
    scanf("%s", s);
    int co = 0;
    for (int i = 0; i < n; i++) if(s[i]=='1') co++;
    if(co==0 || co%2){
      printf("NO\n");
      continue;
    }
    printf("YES\n");
    if(co==n){
      for (int i = 2; i <= n; i++) printf("%d %d\n", 1, i);
      continue;
    }
    int u=0;
    for (int i = 1; i < n; i++) if(s[i]=='0'&&s[i-1]=='1') {
      u = i;
      break;
    }
    for (int i = 0; i < n; i++) if(s[i]=='1'&&(i+1)%n!=u) printf("%d %d\n", u+1, ((i+1)%n)+1);
    for (int i = 0; i < n; i++) if(s[i]=='0') printf("%d %d\n", i+1, ((i+1)%n)+1);
  }   
}