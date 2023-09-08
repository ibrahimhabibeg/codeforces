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
    int pos = 0, neg = 0, mx_indx = 0;
    vector<pair<int, int>> res;
    for (int i = 0; i < n; i++){
      pos+=a[i]>0, neg+=a[i]<0;
      if(abs(a[i])>abs(a[mx_indx])) mx_indx = i;
    }
    if((a[mx_indx]>0&&neg>12)||(a[mx_indx]<0&&pos>12)){
      int x = 0;
      while (a[x]==0||(a[mx_indx]>0 && a[x]>0)||(a[mx_indx]<0 && a[x]<0)) x++;
      mx_indx = x;
      for (int i = 0; i < 5; i++) res.push_back(make_pair(mx_indx, mx_indx));
    } 
    for (int i = 0; i < n; i++) if((a[mx_indx]>0&&a[i]<0)||(a[mx_indx]<0&&a[i]>0)) res.push_back(make_pair(i, mx_indx));
    if(a[mx_indx]>0) for (int i = 0; i < n-1; i++) res.push_back(make_pair(i+1, i));
    else for (int i = n-2; i>=0; i--) res.push_back(make_pair(i, i+1));
    int k = res.size();
    printf("%d\n", k);
    for (int i = 0; i < k; i++) printf("%d %d\n", res[i].first+1, res[i].second+1);
  }   
}