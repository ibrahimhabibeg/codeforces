#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n;
  cin >> TC;
  while (TC--){
    scanf("%d", &n);
    int a[n], b[n];
    vector<int> r(n+1);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    for (int i = 0; i < n; i++) scanf("%d", &b[i]);
    int i = n-1, j = n-1;
    bool isYes = true;
    while (i>=0){
      while (j>0 && b[j-1]==b[j]) r[b[j]]++, j--;
      if(j>=0 && b[j]==a[i]) j--;
      else if(r[a[i]]>0) r[a[i]]--;
      else{
        isYes = false;
        break;
      } 
      i--;
    }
    if(isYes) printf("YES\n");
    else printf("NO\n");
  }   
}