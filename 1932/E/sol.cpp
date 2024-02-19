#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n;
  cin >> TC;
  while (TC--){
    scanf("%d", &n);
    char t[n+1];
    scanf("%s", t);
    int s = 0, r = 0;
    for (int i = 0; i < n; i++) s+=t[i]-'0';
    vector<int> res;
    for (int i = n-1; i>=0; i--){
      int cs = s + r;
      res.push_back(cs%10);
      r = cs/10;
      s -= t[i]-'0';
    }
    while (r) res.push_back(r%10), r/=10;
    int i = res.size() - 1;
    while (res[i]==0) i--;
    while (i>=0) printf("%d", res[i]), i--;
    printf("\n");
  }   
}