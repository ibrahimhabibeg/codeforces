#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n;
  cin >> TC;
  while (TC--){
    scanf("%d", &n);
    int a[n+1], d[n+1], l[n+1], r[n+1];
    set<int> s;
    for (int i = 0; i < n; i++) scanf("%d", &a[i]), s.insert(i);
    for (int i = 0; i < n; i++) scanf("%d", &d[i]);
    for (int i = 0; i < n; i++) l[i] = i-1, r[i] = i+1;
    l[0] = n, a[n] = 0;
    for (int rnd = 0; rnd < n; rnd++){
      vector<int> cc;
      set<int> ns;
      for (auto it = s.begin(); it!=s.end(); it++){
        int i = (*it);
        if(a[l[i]]+a[r[i]]>d[i]){
          cc.push_back(i);
          if(r[i]<n) ns.insert(r[i]);
          if(l[i]<n) ns.insert(l[i]);
        } 
      }
      int res = cc.size();
      for(int i: cc) r[l[i]] = r[i], l[r[i]] = l[i], ns.erase(i);      
      printf("%d ", res);
      s = ns;
    }
    printf("\n");
  }   
}