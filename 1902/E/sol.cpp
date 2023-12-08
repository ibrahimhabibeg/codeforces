#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int S = 26*(1e6+5);
int t[S];

struct TrieNode { 
  struct TrieNode *children[26];
  int cnt;
}; 

struct TrieNode *createNode(void){
  struct TrieNode *pNode =  new TrieNode;
  pNode->cnt = 0;
  for (int i = 0; i < 26; i++) pNode->children[i] = NULL;
  return pNode;
}

int main(){
  int n;
  scanf("%d", &n);
  string s[n];
  for(int i=0; i<n; i++) cin >> s[i];
  int sm = 0;
  struct TrieNode *root = createNode();
  for (int i = 0; i < n; i++){
    sm+=s[i].length();
    struct TrieNode *r = root;
    for (int j = 0; j < s[i].length(); j++){
      if(!r->children[s[i][j]-'a']) r->children[s[i][j]-'a'] = createNode();
      r=r->children[s[i][j]-'a'], r->cnt++;
    } 
  }
  ll res = 2*1ll*n*1ll*sm;
  for (int i = 0; i < n; i++){
    struct TrieNode *r = root;
    for (int j = s[i].length()-1; j >=0; j--){
      if(!r->children[s[i][j]-'a']) break;
      r=r->children[s[i][j]-'a'], res-=2*(r->cnt);
    } 
  }
  printf("%lld\n", res);
}