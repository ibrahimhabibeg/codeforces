#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e3+5;
int cc[N], s[N], n;
set<pair<int, int>> st;

void merge(int a, int b){
  st.erase(make_pair(s[a], a)), st.erase(make_pair(s[b], b));
  s[a]+=s[b], s[b] = 0;
  st.insert(make_pair(s[a], a)), st.insert(make_pair(s[b], b));
  for (int i = 1; i <= n; i++) 
  if(cc[i]==b) cc[i] = a;
}

int main(){
  int q, a, b, k = 1;
  scanf("%d%d", &n, &q);
  for (int i = 1; i <= n; i++) cc[i] = i, st.insert(make_pair(1,i)), s[i]=1;
  while(q--){
    scanf("%d%d", &a, &b);
    if(cc[a]!=cc[b]) merge(cc[a], cc[b]);
    else k++;
    int res = 0;
    auto it = st.end();
    for (int i = 1; i <= k; i++) it--, res+=(*(it)).first;
    printf("%d\n", res-1);
  }
  
}