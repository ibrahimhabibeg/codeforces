#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n, m;
  cin >> TC;
  while (TC--){
    scanf("%d%d", &n, &m);
    int a[n][m], c = 0;
    vector<int> s(n);
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) scanf("%d", &a[i][j]), c+=a[i][j], s[i] += a[i][j];
    if(c%n){
      printf("-1\n");
      continue;
    }
    vector<int> x, y, z;
    for (int j = 0; j < m; j++){
      vector<int> h, l;
      for (int i = 0; i < n; i++){
        if(a[i][j] && s[i]>c/n) h.push_back(i);
        if(a[i][j]==0 && s[i]<c/n) l.push_back(i);
      }
      for (int i = 0; i < min(h.size(), l.size()); i++){
        s[h[i]]--, s[l[i]]++;
        x.push_back(h[i]+1), y.push_back(l[i]+1), z.push_back(j+1);
      }
    }
    printf("%d\n", (int)x.size());
    for (int i = 0; i < x.size(); i++) printf("%d %d %d\n", x[i], y[i], z[i]);
    
  }   
}