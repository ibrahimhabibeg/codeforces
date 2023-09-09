#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n, m, a, b;
  string s;
  cin >> TC;
  while (TC--){
    cin >> n >> m >> s;
    s = '2' + s;
    int l[n+1], r[n+1];
    r[1]=s[1]=='1'?-1:1, l[n]=s[n]=='0'?n+1:n;
    for (int i = 2; i <= n; i++) r[i]=s[i]=='0'?i:r[i-1];
    for (int i = n-1; i >= 1; i--) l[i]=s[i]=='1'?i:l[i+1];
    set<pair<int, int>> fnd;
    for (int i = 0; i < m; i++){
      scanf("%d%d", &a, &b);
      if(l[a]>r[b]) fnd.insert(make_pair(-1,-1));
      else fnd.insert(make_pair(l[a],r[b]));
    }
    int res = fnd.size();
    printf("%d\n", res);
  }
}