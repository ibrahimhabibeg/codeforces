#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n;
  cin >> TC;
  while (TC--){
    scanf("%d", &n);
    int a[n], b[n], s=n, m=0;
    bool isYes = true;
    set<pair<int,int>> st;
    for (int i = 0; i < n; i++) scanf("%d", &a[i]), st.insert(make_pair(a[i], i));
    while (s>0){
      pair<int, int> l = *(st.begin()), r = *(st.rbegin());
      if(l.first-m==0 && r.first-m==s) {isYes=false; break;}
      else if(l.first-m==0) b[l.second]=-s, st.erase(l);
      else if(r.first-m==s) b[r.second]=s, st.erase(r), m++;
      else {isYes=false; break;}
      s--;
    }
    if(isYes){
      printf("YES\n");
      for (int i = 0; i < n; i++) printf("%d ", b[i]);
      printf("\n");
    }
    else printf("NO\n");
  }   
}