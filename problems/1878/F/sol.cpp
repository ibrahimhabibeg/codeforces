#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, q, k, x, n;
  cin >> TC;
  while (TC--)
  {
    scanf("%d%d", &n, &q);
    map<int, int> ogP, p;
    int d, ogD = 1, tn = n;
    for (int i = 2; i <= sqrt(n); i++){
      int c = 0;
      while (n % i == 0) c++, n = n/i;
      if(c) ogP[i] = c, ogD*=c+1;
    }
    if(n>=2) ogD/=ogP[n]+1, ogP[n]++, ogD*=ogP[n]+1;
    p = ogP, d = ogD, n = tn;
    while (q--){
      scanf("%d", &k);
      if(k==2){
        d = ogD, p = ogP;
        continue;
      }
      scanf("%d", &x);
      for (int i = 2; i <= sqrt(x); i++){
        int c = 0;
        while (x % i == 0) c++, x/=i;
        if(c) d/=p[i]+1, p[i]+=c, d*=p[i]+1;
      }
      if(x>=2) d/=p[x]+1, p[x]++, d*=p[x]+1;
      bool isYes = true;
      int td = d;
      for (int i = 2; i <= sqrt(d); i++){
        int c = 0;
        while (d % i == 0) c++, d/=i;
        if(c>p[i]) isYes = false;
      }
      if(d>=2 && p[d]==0) isYes = false;
      d = td;
      if(isYes) printf("YES\n");
      else printf("NO\n");
    }
    printf("\n");
  }   
}