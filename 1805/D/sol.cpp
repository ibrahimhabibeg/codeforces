#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int n, u, v;
  cin >> n;
  vector<int> graph[n];
  for (int i = 0; i < n-1; i++)
  {
    cin >> u >>v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  
}