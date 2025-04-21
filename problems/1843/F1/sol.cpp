#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n, u, v, x, k;
  char c;
  cin >> TC;
  while (TC--){
    scanf("%d", &n);
    int mn[n+1], mx[n+1], mni[n+1], mxi[n+1], y = 2;
    mx[1] = mxi[1] = 1;
    mn[1] = mni[1] = 0;
    for (int i = 0; i < n; i++){
      cin >> c;
      if(c=='+'){
        scanf("%d %d", &v, &x);
        mxi[y] = x+(mxi[v]>0?mxi[v]:0), mni[y] = x+(mni[v]<0?mni[v]:0);
        mx[y] = max(mx[v], mxi[y]), mn[y] = min(mn[v], mni[y]);
        y++;
      }else{
        scanf("%d %d %d", &u, &v, &k);
        if(k<=mx[v]&&k>=mn[v]) printf("YES\n");
        else printf("NO\n");
      }
    }
  }   
}