#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n, b, y;
  cin >> TC;
  while (TC--){
    scanf("%d", &n);
    set<int> s;
    for (int i = 0; i <= n; i++) s.insert(i);
    for (int i = 0; i < n; i++){
      scanf("%d", &b);
      auto it = s.find(b);
      if(it!=s.end()) s.erase(it);
    }
    while (true){
      int x = *(s.begin());
      s.erase(s.begin());
      printf("%d\n", x);
      fflush(stdout);
      scanf("%d", &y);
      if(y==-1) break;
      s.insert(y);
    }
  }   
}