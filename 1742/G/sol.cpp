#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n;
  cin >> TC;
  while (TC--){
    scanf("%d", &n);
    int a[n], b= 0;
    vector<bool> t(n);
    vector<int> v[32], r;
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < n; i++) for (int j = 0; j < 32; j++) if(a[i]&(1<<j)) v[j].push_back(i);
    for (int i = 31; i>=0; i--){
      if(b&(1<<i)) continue;
      int f = -1;
      for(int j: v[i]) if(!t[j]){
        if(f==-1) f= j;
        else if((a[j]&(~b)) > (a[f]&(~b))) f = j;
      }
      if(f!=-1) t[f] = true, r.push_back(f), b|=a[f];
    }
    for (int i = 0; i < n; i++) if(!t[i]) r.push_back(i);
    for (int i = 0; i < n; i++) printf("%d ", a[r[i]]);
    printf("\n");
  }   
}