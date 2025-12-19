// 洛谷P5410 扩展KMP模板题
// 给定两个字符串a，b，需要计算两个数组：
// 1.b的z函数数组
// 2.b与a的每一个后缀的LCP长度数组
// 求出两个数组的权值

#include <bits/stdc++.h>
using namespace std;
vector<int> Z_Algo(const string& s)
{
    //初始化
    int n = s.size();
    vector<int> z(n,0);
    z[0]=n;
    int l = 0, r = 0;   //Z-box [l,r]
    //计算Z函数
    for (int i=1;i<n;i++)
    {
        //利用已有信息加速
        if (i<=r)
        {
            z[i]=min(r-i+1,z[i-l]); 
        }
        //扩展匹配
        //如果选取的是z[i-l] 此时z[i] + i-1<=r 不会超出Z-box 则不会进入下面的while循环
        //如果选取的是r-i+1 在不超出总长度的情况下 则继续扩展匹配 即进入循环
        while (i+z[i]<n && s[z[i]]==s[i+z[i]])
        {
            z[i]++;
        }
        //更新Z-box区间
        if (i+z[i]-1>r)
        {
            l=i;
            r=i+z[i]-1;
        }
    }
    return z;
}

//计算b与a的每一个后缀的LCP长度数组
vector<int>combinary_lcp(const string& s,const string& t)
{
    int s_len=s.size();
    int t_len =t.size();
    string combined;
    combined.reserve(s_len+t_len+1);
    combined = s + "#" + t;   //连接字符串

    vector<int> z = Z_Algo(combined); //计算Z函数
    vector<int> result(t_len,0);
    for (int i=0;i<t_len;i++)
    {
        result[i]=z[i + s_len + 1]; //提取LCP长度
    }
    return result;
}
//计算权值
long long calculate_weight(vector<int>& arr)
{
    long long result =0;
    for (int i=0;i<arr.size();i++)
    {
        result ^=(1LL * (i+1) * (arr[i]+1));
    }
    return result;
}

int main()
{
    string a,b;
    cin>>a>>b;
    vector<int> z_b = Z_Algo(b);
    vector<int> combine = combinary_lcp(b,a);;
    cout<<calculate_weight(z_b)<<"\n";
    cout<<calculate_weight(combine)<<"\n";
    return 0;
}
