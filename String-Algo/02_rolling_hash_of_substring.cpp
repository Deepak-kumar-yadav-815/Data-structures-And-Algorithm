#include<bits/stdc++.h>
using namespace std;

#define int long long
const int p = 31;
const int mod = 1e9+7;

vector<int> dp;
vector<int> power_p;
vector<int> inv;

int power(int a, int b){
    int res = 1;
    while(b){
        if(b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

void buildHash(string &s){
    int n = s.size();
    dp.resize(n);
    power_p.resize(n);
    inv.resize(n);
    power_p[0] = 1;
    for(int i = 1; i < n; i++)
        power_p[i] = (power_p[i-1] * p) % mod;
    int inv_p = power(p, mod-2);
    inv[0] = 1;
    for(int i = 1; i < n; i++)
        inv[i] = (inv[i-1] * inv_p) % mod;
    dp[0] = (s[0] - 'a' + 1);
    for(int i = 1; i < n; i++){
        dp[i]=(dp[i-1]+(s[i] - 'a' + 1)*power_p[i])%mod;
    }
}

int getSubstringHash(int l, int r){
    int result = dp[r];
    if(l > 0)result = (result - dp[l-1] + mod) % mod;   
    result = (result * inv[l]) % mod;
    return result;
}
signed main(){
    string s;
    cin >> s;
    buildHash(s);
    int l, r;
    cin >> l >> r;
    cout << getSubstringHash(l, r) << endl;
}
