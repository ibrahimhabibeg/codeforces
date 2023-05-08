#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n, m, v;
  cin >> TC;
  while (TC--)
  {
    scanf("%d", &n);
    int a[n], b[n];
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < n; i++) scanf("%d", &b[i]);
    scanf("%d", &m);
    map<int, int> mp;
    for (int i = 0; i < m; i++) { scanf("%d", &v); mp[v]++;}
    stack<int> s;
    bool isYes = true;
    for (int i = 0; i < n; i++)
    {
      if(a[i]<b[i]) {isYes=false; break;}
      while (!s.empty() && s.top()<b[i]) s.pop();
      if(a[i]==b[i] || (!s.empty() && s.top()==b[i])) continue;
      if(mp[b[i]]--<=0){isYes=false; break;}
      s.push(b[i]);
    }
    printf((isYes?"YES\n":"NO\n"));
  }   
}