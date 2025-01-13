#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
  int l, r, n;
  scanf("%d%d", &l, &r);
  int a = r, b =l;
  vector<int> va, vb;
  while(r){
    va.push_back(r%2);
    vb.push_back(l%2);
    r/=2, l/=2;
  }
  n = va.size();
  int c1 = 0, i = n-1, c2 = 0;
  while (i>=0 && va[i]==vb[i]) c1+=va[i]<<i, i-=1;
  i--;
  while(i>=0 && vb[i]==1) c1+=1<<i, i-=1;
  while(i>=0) c1+=(1-vb[i])<<i, i-=1;

  i = n-1;
  while (i>=0 && va[i]==vb[i]) c2+=va[i]<<i, i-=1;
  c2+=va[i]<<i;
  i--;
  while(i>=0 && va[i]==0) i-=1;
  while(i>=0) c2+=(1-va[i])<<i, i-=1;
  printf("%d %d ", a, b);
  if((a^c1)+(b^c1) > (a^c2)+(b^c2)) printf("%d\n", c1);
  else printf("%d\n", c2);
}

int main(){
  int TC;
  scanf("%d", &TC);
  while(TC--){
    solve();
  }
}