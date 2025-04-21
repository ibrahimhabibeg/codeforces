#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n;
  cin >> TC;
  while (TC--){
    scanf("%d", &n);
    int k[n], h[n], s[n];
    for (int i = 0; i < n; i++) scanf("%d", &k[i]);
    for (int i = 0; i < n; i++) scanf("%d", &h[i]);
    for (int i = 0; i < n; i++) s[i] = k[i] - h[i] + 1;
    set<pair<int, int>> st;
    st.insert(make_pair(k[0], s[0]));
    for (int i = 1; i < n; i++){
      auto it = st.lower_bound(make_pair(s[i], 0));
      if(it==st.end()){
        st.insert(make_pair(k[i], s[i]));
        continue;
      }
      int ns = min(s[i], (*it).second);
      while (it!=st.end()){
        auto rm = it;
        it++;
        st.erase(rm);
      }
      st.insert(make_pair(k[i], ns));
    }
    ll res = 0;
    for (auto it = st.begin(); it!=st.end(); it++){
      ll a= (*it).second, b = (*it).first;
      res += ((b-a+1)*(b-a+2))/2;
    } 
    printf("%lld\n", res);
  }   
}