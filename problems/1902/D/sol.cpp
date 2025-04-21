#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int n, q, x, y, l, r;
  scanf("%d%d", &n, &q);
  char s[n+1];
  scanf("%s", s);
  int px[n+1], py[n+1];
  px[0] = py[0] = 0;
  set<pair<pair<int,int>,int>> st;
  st.insert(make_pair(make_pair(0,0),0));
  for (int i = 0; i < n; i++){
    px[i+1] = px[i], py[i+1] = py[i];
    if(s[i]=='U') py[i+1]++;
    else if(s[i]=='D') py[i+1]--;
    else if(s[i]=='R') px[i+1]++;
    else px[i+1]--;
    st.insert(make_pair(make_pair(px[i+1],py[i+1]),i+1));
  }
  while(q--){
    scanf("%d%d%d%d", &x, &y, &l, &r);
    auto it = st.lower_bound(make_pair(make_pair(x, y), 0));
    if(it!=st.end() && (*it).first.first==x && (*it).first.second==y && (*it).second<l){
      printf("YES\n");
      continue;
    }
    it = st.lower_bound(make_pair(make_pair(x, y), r));
    if(it!=st.end() && (*it).first.first==x && (*it).first.second==y){
      printf("YES\n");
      continue;
    }
    it = st.lower_bound(make_pair(make_pair(px[l-1]+px[r]-x, py[l-1]+py[r]-y), l));
    if(it!=st.end() && (*it).first.first==px[l-1]+px[r]-x && (*it).first.second==py[l-1]+py[r]-y && (*it).second<r){
      printf("YES\n");
      continue;
    }
    printf("NO\n");
  }   
}