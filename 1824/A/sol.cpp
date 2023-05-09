#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n, m, v;
  cin >> TC;
  while (TC--)
  {
    scanf("%d %d", &n, &m);
    vector<bool> added(m+1);
    int l = 0, r = 0;
    vector<int> chairs;
    for (int i = 0; i < n; i++)
    {
      scanf("%d", &v);
      l += v==-1, r+= v==-2;
      if(v>0 && !added[v]){
        added[v] = true;
        chairs.push_back(v);
      }
    }
    sort(chairs.begin(), chairs.end());
    int u = (int) chairs.size();
    int res = max(min(m, r + u), min(m, l + u));
    for (int i = 0; i < (int) chairs.size(); i++)
    {
      res = max(res, 1 + min(i+l, chairs[i]-1) + min(u-i-1+r, m - chairs[i]));
    }
    printf("%d\n", res);
  }   
}