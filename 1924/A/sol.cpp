#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n, k, m;
  cin >> TC;
  while (TC--)
  {
    scanf("%d%d%d", &n, &k, &m);
    int full = (1<<k) - 1, mask  = 0, lvl = 0;
    char s[m+1], res[n+1];
    res[n] = '\0';
    scanf("%s", s);
    for (int i = 0; i < m; i++){
      int c = s[i] - 'a';
      mask |= (1<<c);
      if(mask==full){
        res[lvl] = 'a' + c;
        lvl++;
        if(lvl==n) break;
        mask = 0;
      }
    }
    if(lvl==n){
      printf("YES\n");
    }else{
      printf("NO\n");
      int z = 0;
      while (mask%2) z++, mask/=2;
      res[lvl] = 'a' + z;
      lvl++;
      for (int i = lvl; i < n; i++) res[i] = 'a';
      printf("%s\n", res);
    }
    
  }   
}