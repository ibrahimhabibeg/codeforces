#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n, x;
  cin >> TC;
  while (TC--){
    scanf("%d", &n);
    vector<int> c(n+1);
    c[0] = 1;
    for (int i = 0; i < n-1; i++) scanf("%d", &x), c[x]++;
    sort(c.begin(), c.end());
    int i = n, res = 0, inf = 0;
    multiset<int> s;
    while (c[i]) res = max(res, c[i]+n-i),s.insert(c[i]+n-i), i--, inf++ ;
    while (res>inf){
      auto it = --s.end();
      int v = *it;
      s.erase(it), s.insert(v-1);
      inf ++, res = *s.rbegin();
    }
    printf("%d\n", max(res, inf));
  }   
}