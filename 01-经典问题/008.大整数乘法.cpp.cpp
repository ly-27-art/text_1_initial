#include <bits/stdc++.h>
using namespace std;
string dict="0123456789";
const int N=10005;
int a[N],b[N],c[N];
int lena,lenb,lenc;
int init(int a[],string s){
    int len=s.size();
    for(int i=0;i<len;i++){
        a[i]=s[len-1-i]-'0';
    }
    return len;
}
void multi()
{
    for(int i=0;i<lena;i++){
        for(int j=0;j<lenb;j++){
            int w=i+j;
            c[w]+=a[i]*b[j];
            c[w+1]+=c[w]/10;
            c[w]%=10;
        }
    }
    lenc = lena+lenb;
    while(lenc>0&&c[lenc]==0) lenc--;
    for(int i=lenc;i>=0;i--) cout<<c[i];
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    lena=init(a,s1);
    lenb=init(b,s2);
    multi();
    return 0;
}