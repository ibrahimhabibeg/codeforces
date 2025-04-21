#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int cnt(int x){
  int res = 0;
  while(x){
    res++, x/=2;
  }
  return res;
}

int MOD = 1e9+7;

int main(){
  int n, p;
  scanf("%d%d", &n, &p);
  int a[n];
  vector<int> f(p+1);
  set<int> s;
  for (int i = 0; i < n; i++) scanf("%d", &a[i]), s.insert(a[i]);
  for (int i = 0; i < n; i++){
    int x = a[i];
    bool isYes = true;
    while (x&&(x%4==0||x%2==1)){
      if(x%4==0) x/=4;
      else x/=2;
      if(s.find(x)!=s.end()){
        isYes = false;
        break;
      }
    }
    int c = cnt(a[i]);
    if(isYes&&c<=p) f[cnt(a[i])]++;
  }
  int res = f[1];
  for (int i = 2; i <= p; i++) {
    f[i] = (f[i]+(f[i-1]+f[i-2])%MOD)%MOD;
    res = (res+f[i])%MOD;
  }
  printf("%d\n", res);
  
}