#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n, m;
  cin >> TC;
  while (TC--){
    scanf("%d%d", &n, &m);
    int a[n][m], b[n][m], res = 1;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) scanf("%d", &a[i][j]);
    for (int i = 0; i < n; i++){
      set<pair<int, int>> s;
      s.insert(make_pair(a[i][0],0));
      b[i][0] = 1;
      for (int j = 1; j < m; j++) {
        int L = b[i][j-1]+1;
        s.insert(make_pair(a[i][j],j));
        auto p = *(s.begin());
        while (p.first<L) s.erase(make_pair(a[i][j-L+1],j-L+1)), L--, p = *(s.begin());
        b[i][j] = L;
      }
    }
    for (int j = 0; j < m; j++){
      set<pair<int, int>> s;
      s.insert(make_pair(b[0][j],0));
      int L = 1;
      for (int i = 1; i < n; i++) {
        L++;
        s.insert(make_pair(b[i][j],i));
        auto p = *(s.begin());
        while (p.first<L) s.erase(make_pair(b[i-L+1][j],i-L+1)), L--, p = *(s.begin());
        res = max(res,L);
      }
    }
    printf("%d\n", res); 
  }   
}