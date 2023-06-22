#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 200005;
vector<int> adj[N];
int sz[N];

int dfs(int u){
  if(sz[u]!=0) return sz[u];
  sz[u] = 1;
  for(int v: adj[u]) sz[u]+= dfs(v);
  return sz[u];
}

int main(){
  int TC, k;
  string s;
  cin >> TC;
  while (TC--){
    scanf("%d", &k); cin >> s;
    int n = s.length();
    for (int i = 0; i < n; i++) sz[i] = 0, adj[i].resize(0);
    stack<int> st;
    for (int i = 0; i < n; i++){
      if(s[i]=='('){
        if(!st.empty()) adj[st.top()].push_back(i);
        st.push(i);
      }else st.pop();
    }
    for (int i = 0; i < n; i++) dfs(i);
    sort(sz, sz+n);
    ll res = 0;
    for (int i = 0; i < n-k; i++) res += sz[i]-1;
    printf("%lld\n", res);
  }   
}