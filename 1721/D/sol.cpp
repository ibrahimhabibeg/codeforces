#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n;
  cin >> TC;
  while (TC--){
    scanf("%d", &n);
    vector<vector<int>> a(1, vector<int>(n)), b(1, vector<int>(n));
    for (int i = 0; i < n; i++) scanf("%d", &a[0][i]);
    for (int i = 0; i < n; i++) scanf("%d", &b[0][i]);
    int res = 0, bn = 1;
    for (int k = 29; k >= 0; k--){
      vector<vector<int>> na(2*bn), nb(2*bn);
      bool isYes = true;
      for (int j = 0; j<bn; j++){
        for(int v: a[j]){
          if((v>>k)%2) na[2*j+1].push_back(v);
          else na[2*j].push_back(v);
        }
        for(int v: b[j]){
          if((v>>k)%2) nb[2*j].push_back(v);
          else nb[2*j+1].push_back(v);
        }
        if(na[2*j].size()!=nb[2*j].size()){
          isYes = false;
          break;
        }
      }
      if(isYes){
        res+=1<<k, bn<<=1;
        a.clear(), b.clear();
        int nbn=0;
        for (int j = 0; j<bn; j++) if(na[j].size()!=0) a.push_back(na[j]), nbn++;
        for (int j = 0; j<bn; j++) if(nb[j].size()!=0) b.push_back(nb[j]);
        bn = nbn;
      } 
    } 
    printf("%d\n", res);
  }   
}