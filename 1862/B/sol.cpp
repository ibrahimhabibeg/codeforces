#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n;
  cin >> TC;
  while (TC--){
    scanf("%d", &n);
    int b[n];
    vector<int> res;
    for (int i = 0; i < n; i++) scanf("%d", &b[i]);
    res.push_back(b[0]);
    for (int i = 1; i < n; i++) {
      if(b[i]<b[i-1]) res.push_back(b[i]);
      res.push_back(b[i]);
    }
    printf("%d\n", (int) res.size());
    for (int i = 0; i < res.size(); i++) printf("%d ", res[i]);
    printf("\n");
  }   
}