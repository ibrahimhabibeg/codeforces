#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int n , m , q, l, r, j, res = 0, ones = 0;
  scanf("%d%d%d", &n, &m ,&q);
  string s; 
  cin >> s;
  s = ' ' +s;
  set<int> st;
  vector<int> ord, mp(n+1, -1);
  for(int i = 1; i<=n; i++) st.insert(i);
  for(int i = 0; i<m; i++){
    scanf("%d%d", &l, &r);
    auto f = st.lower_bound(l);
    while (f!=st.end() && *f <= r){
      ord.push_back(*f);
      st.erase(f);
      f = st.lower_bound(l);
    }
  } 
  int c = ord.size();
  for(int i = 0; i<c; i++) mp[ord[i]] = i;
  for(int i = 1; i<=n; i++) ones+=s[i]=='1';
  for(int i = 0; i<min(ones, c); i++) res+=s[ord[i]]=='0';
  for (int i = 0; i < q; i++){
    scanf("%d", &j);
    s[j]=s[j]=='0'?'1':'0';
    if(mp[j]>=0 && mp[j]<ones) res+=s[j]=='0'?1:-1;
    if(s[j]=='1'){
      if(ones<c) res+=s[ord[ones]]=='0';
      ones++;
    }else{
      ones--;
      if(ones<c) res-=s[ord[ones]]=='0';
    }
    printf("%d\n", res);
  }
}