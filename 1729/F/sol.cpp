#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, w, q, l, r, k;
  cin >> TC;
  string s;
  while (TC--){
    cin >> s;
    int n = s.length();
    scanf("%d%d", &w, &q);
    int sum = 0, b[n+1];
    b[0] = 0;
    set<int> st[9];
    for (int i = 0; i < w; i++) sum=(sum+(s[i]-'0'))%9;
    st[sum].insert(1);
    for (int i = w; i < n; i++) sum=(((sum+(s[i]-'0')-(s[i-w]-'0'))%9)+9)%9, st[sum].insert(i-w+2);
    for (int i = 1; i <= n; i++) b[i] = (b[i-1]+(s[i-1]-'0'))%9;
    while(q--){
      scanf("%d%d%d", &l, &r, &k);
      int d = (b[r]-b[l-1]+9)%9, r1 = -1, r2 = -1;
      for (int i = 0; i < 9; i++){
        auto it = st[i].begin();
        if(it==st[i].end()) continue;
        it++;
        int cr2 = n+5;
        if((i*d+i)%9==k&&it!=st[i].end()) cr2 = *it;
        for (int j = 0; j < 9; j++) 
        if((i*d+j)%9==k && i!=j && st[j].begin()!=st[j].end()) cr2 = min(cr2, *(st[j].begin()));
        if(cr2<n+5){
          int cr1 = *(st[i].begin());
          if(r1==-1 || cr1<r1 || (cr1==r1 && cr2<r2))r1 = cr1, r2 = cr2;
        }
      }
      printf("%d %d\n", r1, r2);
    }
  }   
}