#include <bits/stdc++.h>
using namespace std;
const int N=1001;
int a[N],b[N],c[N];
int main()
{
    string s1,s2;
    cin>>s1>>s2;
    int n=s1.length();
    int m=s2.length();
    // 将字符串存储到数组中 注意逆序存储
    for(int i=0;i<n;i++)
    {
        a[n-i]=s1[i]-'0';
    }
    for(int i=0;i<m;i++)
    {
        b[m-i]=s2[i]-'0';
    }
    // 进行加法运算
    int len=max(n,m);
    for (int i=1;i<=len;i++)
    {
        c[i]+=a[i]+b[i];
        c[i+1]+=c[i]/10;
        c[i]%=10;
    }
    // 处理最高位进位
    if (c[len+1]!=0)
    {
        len++;
    }
    // 输出结果 注意逆序输出
    for (int i=len;i>=1;i--)
    {
        cout<<c[i];
    }
    return 0;
}