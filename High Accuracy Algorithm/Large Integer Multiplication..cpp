#include <bits/stdc++.h>
using namespace std;
const int MAXN=40500;
int a[MAXN],b[MAXN],c[MAXN];
int main()
{
    string s1,s2;
    cin>>s1;
    cin>>s2;
    int n=s1.size();
    int m=s2.size();
    int len=n+m;
    for(int i=0;i<n;i++)
    {
        a[n-i]=s1[i]-'0';
    }
    for (int i=0;i<m;i++)
    {
        b[m-i]=s2[i]-'0';
    }
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            c[i+j-1]+=a[i]*b[j];
        }
    }
    for (int i=1;i<len;i++)
    {
        if (c[i]>=10)
        {
            c[i+1]+=c[i]/10;
            c[i]%=10;
        }
    }
    while (c[len]==0&&len>1)
    {
        len--;
    }
    for (int i=len;i>=1;i--)
    {
        cout<<c[i];
    }
    return 0;
}