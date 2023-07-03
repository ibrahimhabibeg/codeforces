#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll M = 1e9;
ll B = 1e6;

int main(){
  int TC, n, v;
  cin >> TC;
  while (TC--){
    scanf("%d", &n);
    map<int, int> c;
    for (int i = 0; i < n; i++){
      scanf("%d", &v);
      c[v]++;
    }
    ll res = 0;
    for (auto it : c){
      int a=it.first;
      res+=c[a]*1LL*(c[a]-1)*1LL*(c[a]-2);
      if(a>B){
        for (int k = 2; k*a<=M; k++) if(a%k==0) if(c.find(a/k)!=c.end() && c.find(a*k)!=c.end()) res+=c[a]*1LL*c[a/k]*1LL*c[a*k];
      } else{
        for (int k = 2; k*k<=a; k++) if(a%k==0){
          if(a*1LL*k<=M && c.find(a/k)!=c.end() && c.find(a*k)!=c.end()) res+= c[a]*1LL*c[a/k]*1LL*c[a*k];
          if(k*k<a && a*1LL*(a/k)<=M && c.find(a/(a/k))!=c.end() && c.find(a*(a/k))!=c.end()) res+= c[a]*1LL*c[a/(a/k)]*1LL*c[a*(a/k)];
        }
        if(a>1 && a*1LL*a<=M && c.find(1)!=c.end() && c.find(a*a)!=c.end()) res+=c[1]*1LL*c[a]*1LL*c[a*a];
      } 
    }
    printf("%lld\n", res);
  }   
}