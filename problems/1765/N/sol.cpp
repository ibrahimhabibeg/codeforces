#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main(){
  int TC, k;
  cin >> TC;
  string s;
  while (TC--)
  {
    cin >> s;
    scanf("%d", &k);
    int n = s.length();
    char res[n-k+1];
    res[n-k] ='\0';
    int j = 0, b = 0, ws=k+1, c=0;
    set<pair<char,int>> st;
    while (j<n&&c<n-k){
      while (j-b+1<=ws) st.insert(make_pair(s[j],j)), j++;
      auto it = st.begin();
      while (c==0&&(*it).first=='0') it++;
      int mn = (*it).second;
      char nc = (*it).first;
      for (int i = b; i <= mn; i++) st.erase(make_pair(s[i],i));
      ws-=mn-b, b=mn+1;
      res[c]=nc;
      c++;
    }
    printf("%s\n",res);
  }   
}