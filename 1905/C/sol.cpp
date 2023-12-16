#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n;
  cin >> TC;
  char cr;
  while (TC--){
    scanf("%d", &n);
    int a[n], b[n];
    char s[n+1];
    scanf("%s", s);
    for (int i = 0; i < n; i++) a[i] = s[i]-'a';
    b[n-1] = n-1;
    vector<int> c;
    c.push_back(n-1);
    for (int i = n-2; i>=0 ; i--){
      if(a[i]>=a[b[i+1]]) b[i] = i, c.push_back(i);
      else b[i] = b[i+1];
    }
    int j = 0, x = a[0];
    bool isSorted = true;
    if(b[0]==0) x=a[c[j]], j++;
    for (int i = 1; i < n; i++){
      int y = a[i];
      if(b[i]==i) y = a[c[j]], j++;
      if(x>y){
        isSorted = false;
        break;
      }
      x = y;
    }
    if(!isSorted){
      printf("-1\n");
    }else{
      int ln = c.size(), cnt = 0;
      for (int i = ln-1; i>=0; i--) if(a[c[i]]==a[c[ln-1]]) cnt++;
      printf("%d\n", ln-cnt);
      
    }
  }   
}