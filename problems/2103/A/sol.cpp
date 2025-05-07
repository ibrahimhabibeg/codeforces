#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }
  set<int> s;
  for(int i = 0; i < n; i++){
    s.insert(a[i]);
  }
  cout << s.size() << endl;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int TC = 1;
  cin >> TC;
  while(TC--){
    solve();
  }
}