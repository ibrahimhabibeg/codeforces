#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n, q, x;
  cin >> TC;
  while (TC--){
    scanf("%d", &n);
    tuple<int, int, int, int> a[n];
    for (int i = 0; i < n; i++) scanf("%d%d%d%d", &get<0>(a[i]), &get<1>(a[i]), &get<2>(a[i]), &get<3>(a[i]));
    sort(a, a+n);
    int nl = get<0>(a[0]), nb = get<3>(a[0]);
    set<pair<int, int>> st; 
    for (int i = 1; i < n; i++) {
      if(nb>=get<0>(a[i])) nb = max(nb, get<3>(a[i]));
      else st.insert(make_pair(nl, nb)), nl = get<0>(a[i]), nb = get<3>(a[i]);
    }
    st.insert(make_pair(nl, nb));
    scanf("%d", &q);
    while (q--){
      scanf("%d", &x);
      auto p = st.upper_bound(make_pair(x, 1e9));
      if(p==st.begin()) printf("%d ", x);
      else{
        p--;
        printf("%d ", max(x, (*p).second));
      }
    }
    printf("\n");
  }   
}