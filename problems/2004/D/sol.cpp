#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

map<char, int> cmp;

int comb[6];
int num[4];

void solve(){
  int n, q;
  scanf("%d%d", &n, &q);
  map<int, set<int>> mp;
  for(int i: comb){
    mp[i] = set<int>();
  }
  int a[n+1][2];
  for(int i = 1; i <= n; i++){
    char c[3];
    scanf("%s", c);
    int c1 = cmp[c[0]], c2 = cmp[c[1]];
    a[i][0] = c1;
    a[i][1] = c2;
    mp[c1*c2].insert(i);
  }
  while (q--){
    int x, y;
    scanf("%d%d", &x, &y);
    int res;
    if(a[x][0] == a[y][0] || a[x][0] == a[y][1] || a[x][1] == a[y][0] || a[x][1] == a[y][1]){
      res = abs(x-y);
    }else {
      res = 1e9;
      for(int i = 0; i < 6; i++) if((comb[i]!= a[x][0] * a[x][1]) && (comb[i]!= a[y][0] * a[y][1])){
        auto it = mp[comb[i]].upper_bound(x);
        if(it != mp[comb[i]].end()){
          res = min(abs(x-*it) + abs(y-*it), res);
        }
        if(it != mp[comb[i]].begin()){
          it--;
          res = min(abs(x-*it) + abs(y-*it), res);
        }
      }
      if(res == 1e9) res = -1;
    }
    printf("%d\n", res);
  }
}

int main(){
  num[0] = 2;
  num[1] = 3;
  num[2] = 5;
  num[3] = 7;
  int cnt = 0;
  for (int i = 0; i < 4; i++) for(int j = i+1; j < 4; j++) {
    comb[cnt] = num[i] * num[j];
    cnt++;
  }
  int TC;
  cmp['B'] = 2;
  cmp['G'] = 3;
  cmp['R'] = 5;
  cmp['Y'] = 7;
  scanf("%d", &TC);
  while(TC--){
    solve();
  }
}