#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n, q, t, v, j;
  cin >> TC;
  while (TC--)
  {
    scanf("%d%d", &n, &q);
    int s = 0, a[n];
    set<int> ons;
    for (int i = 1; i <= n; i++){
      scanf("%d", &a[i]), s+=a[i];
      if(a[i]==1) ons.insert(i);
    }
    while (q--){
      scanf("%d", &t);
      if(t==1){
        scanf("%d", &v);
        bool isYes;
        if((v-s)%2){
          if(ons.size()==0) isYes = false;
          else{
            int l = *(ons.begin()), r  = *(ons.rbegin());
            isYes = s-2*l+1>=v || s-2*(n-r)-1>=v;
          }
        }else isYes = s>=v;
        if(isYes) printf("YES\n");
        else printf("NO\n");
      }else{
        scanf("%d%d", &j, &v);
        s+=v-a[j], a[j] = v;
        if(v==2) ons.erase(j);
        else ons.insert(j);
      }
    }
    
  }   
}