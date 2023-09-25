#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n, k;
  cin >> TC;
  while (TC--){
    scanf("%d", &n);
    vector<int> s[n];
    vector<int> mp(51);
    int ms = 0, res = 0;
    for (int i = 0; i < n; i++)
    {
      scanf("%d", &k);
      s[i].resize(k);
      for (int j = 0; j < k; j++)
      {
        scanf("%d", &s[i][j]), ms+=mp[s[i][j]]==0, mp[s[i][j]]++;
      }
    }
    for(int v = 1; v<=50; v++){
      vector<int> m(51);
      int r = ms;
      for (int i = 0; i < n; i++){
        bool isYes = false;
        for(int j: s[i]) if(j==v) {
          isYes = true;
          break;
        }
        if(isYes) for(int j: s[i]) m[j]++, r-=m[j]==mp[j];
      }
      if(r<ms) res = max(res, r);
    }
    printf("%d\n", res);
  }   
}