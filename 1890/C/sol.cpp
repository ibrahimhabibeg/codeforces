#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int TC, n;
  cin >> TC;
  while (TC--)
  {
    scanf("%d", &n);
    string s;
    cin >> s;
    int cnt0 = 0, cnt1 = 0;
    for (int i = 0; i < n; i++) cnt0+=s[i]=='0', cnt1+=s[i]=='1';
    if(cnt0!=cnt1){
      printf("-1\n");
      continue;
    }
    vector<int> res;
    int l = 0, r = n-1;
    int b = 0;
    while(l<r){
      if(s[l]!=s[r]) l++,r--;
      else if(s[l]=='0'){
        s = s.insert(r+1,"01");
        res.push_back(r+1);
        l++, r++;
      }else{
        s = s.insert(l, "01");
        res.push_back(l);
        l++, r++;
      }
    }
    int m = res.size();
    printf("%d\n", m);
    for (int v: res) printf("%d ", v);
    printf("\n");
  }   
}