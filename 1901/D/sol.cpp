#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int n;
  scanf("%d", &n);
  int a[n];
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  multiset<int> s;
  s.insert(a[0]);
  for (int i = 1; i < n; i++) s.insert(a[i]+i);
  int res = *(s.rbegin());
  for (int i = 1; i < n; i++) {
    s.erase(s.find(a[i]+i));
    s.erase(s.find(a[i-1]));
    s.insert(a[i]);
    s.insert(a[i-1]+n-i);
    res = min(res, *(s.rbegin()));
  }
  printf("%d\n", res);
  
}