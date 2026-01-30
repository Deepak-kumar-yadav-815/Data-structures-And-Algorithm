#include<bits/stdc++.h>
using namespace std;
#define int long long int

int getHash(string & g){
    int value =0;
    int power_p =1;
    int p = 31;
    for(char ch : g){
        value+=((ch-'a'+1)*power_p);
        power_p*=p;
    }
    return value;
}

signed main() {
    bool flag = true;
    while(flag){
        cout<<"ENTER STRING\n";
        string text;
        getline(cin,text);
        if(text == "exit"){
            flag = false;
            continue;
        }
        cout<<getHash(text)<<endl;
    }
}
