//(h.k)
#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL)
#define test(t) int t;cin>>t;while(t--)
#define all(x) begin(x),end(x)
bool match(int left,int right,string&text,string& pattern){
    for(int i=0;i<=right-left;i++){
        if(text[i+left]!=pattern[i])return false;
    }
    return true;
}
signed main() {
  fast;
  string text,pattern;
  getline(cin,text);
  getline(cin,pattern);
  int length_of_text = text.size();
  int length_of_pattern = pattern.size();
  vector<int>indix;
  
  for(int left =0,right = length_of_pattern-1;right<length_of_text;left++,right++){
    if(match(left,right,text,pattern)){
        indix.push_back(left);
    }
  }
  for(auto it :indix){
    cout<<it<<" ";
  }
}
