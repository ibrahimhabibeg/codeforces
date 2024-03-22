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
    bool res = false;
    for (int j = 0; j <= n; j++){
      vector<int> b;
      for (int i = j-1; i >= 0; i--){
        int c = a[i];
        if(a[i]==0) b.push_back(0);
        while(c) b.push_back(c%10), c/=10; 
      }
      bool isYes = true;
      for (int i = 0; i < (int)(b.size())-1; i++) if(b[i]<b[i+1]) isYes = false;
      for (int i = j; i < n-1; i++) if(a[i]>a[i+1]) isYes = false;
      if(j<n && j>0 && a[j]<b[0]) isYes = false;
      res = res || isYes;
    }
    if(res) printf("YES\n");
    else printf("NO\n");
  }   
}