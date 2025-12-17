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
    // 将字符串存储到数组中 注意逆序存储
    for(int i=0;i<n;i++)
    {
        a[n-i]=s1[i]-'0';
    }
    for (int i=0;i<m;i++)
    {
        b[m-i]=s2[i]-'0';
    }
    // 对每一位进行乘法运算
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            c[i+j-1]+=a[i]*b[j];
        }
    }
    // 处理进位
    for (int i=1;i<len;i++)
    {
        if (c[i]>=10)
        {
            c[i+1]+=c[i]/10;
            c[i]%=10;
        }
    }
    // 去除前导零
    while (c[len]==0&&len>1)
    {
        len--;
    }
    // 输出结果 注意逆序输出
    for (int i=len;i>=1;i--)
    {
        cout<<c[i];
    }
    return 0;
}