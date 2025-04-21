#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC,n, q, v;
  cin >> TC;
  int p[31];
  p[0] = 1;
  for (int i = 1; i < 31; i++) p[i]=p[i-1]<<1;
  while (TC--)
  {
    scanf("%d%d", &n, &q);
    int a[n];
    vector<int> b[31];
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < n; i++){
      int j = 0;
      while (j+1<31&&(a[i]%p[j+1])==0) j++;
      b[j].push_back(i);
    }
    while (q--){
      scanf("%d", &v);
      for (int j = v; j < 31; j++){
        for (int i: b[j]) a[i]+=1<<(v-1), b[v-1].push_back(i);
        b[j].clear();
      }
    }
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
  }   
}