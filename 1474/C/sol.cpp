#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
  int TC, n;
  cin >> TC;
  while (TC--){
    scanf("%d", &n);
    int a[2*n], b[n], c[n];
    multiset<int> st;
    for (int i = 0; i < 2*n; i++) scanf("%d", &a[i]);
    sort(a, a+2*n);
    bool isYes = false;
    for (int j = 0; j < 2*n-1; j++){
      st.clear();
      for (int i = 0; i < 2*n; i++) st.insert(a[i]);
      b[0] = a[2*n-1], c[0] = a[j];
      st.erase(st.find(c[0])), st.erase(st.find(b[0]));
      bool isYes2 = true;
      for (int i = 1; i < n; i++){
        auto bit = --st.end();
        int bv = *bit;
        st.erase(bit);
        auto cit = st.find(b[i-1]-bv);
        if(cit==st.end()){
          isYes2 = false;
          break;
        }
        c[i] = *cit, b[i] = bv;
        st.erase(cit);
      }
      if(isYes2){
        isYes = true;
        break;
      }
    }
    if(isYes){
      printf("YES\n%d\n", b[0]+c[0]);
      for (int i = 0; i < n; i++) printf("%d %d\n", b[i], c[i]);
    }else printf("NO\n");
  }   
}