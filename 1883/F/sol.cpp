#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n;
  cin >> TC;
  while (TC--){
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    vector<ll> b(n);
    set<int> s;
    for (int i = n-1; i >=0; i--) if(s.find(a[i])==s.end())s.insert(a[i]),b[i]++;
    for (int i = n-2; i >=0; i--)b[i]+=b[i+1];
    s.clear();
    ll res =0;
    for (int i = 0; i < n; i++) if(s.find(a[i])==s.end()) res+=b[i], s.insert(a[i]);
    printf("%lld\n",res);
  }   
}