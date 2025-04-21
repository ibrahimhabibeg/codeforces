#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n;
  cin >> TC;
  while (TC--)
  {
    scanf("%d", &n);
    pair<int, int> a[n];
    for (int i = 0; i < n; i++) scanf("%d %d", &a[i].second, &a[i].first);
    sort(a, a+n);
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) for (int j = 0; j< i; j++) if(a[i].second<=a[j].first) 
      v.push_back(make_pair(min(a[i].second, a[j].second), a[i].first));
    int cnt = 0, end = -1;
    for(pair<int, int> p: v) if(p.first>end) cnt++, end = p.second;
    printf("%d\n", n-2*cnt);
  }   
}