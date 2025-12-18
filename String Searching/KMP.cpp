#include <bits/stdc++.h>
using namespace std;
// 计算字符串的next数组
vector<int> comp_next(string s)
{
    //初始化 让next[0]=0
    vector<int> next(1,0);
    //prefix_len表示共同前后缀的长度
    int prefix_len=0;
    int i=1;
    //用递推的方式计算next数组
    //原理是 可以接着上一位的匹配再往后判断是否相等 若相等 则next数组的下一位的值等于next数组的前一位的值+1
    //如果不等于 再在该字串中找更短的前后缀继续比较 长度即为next[prefix_len-1]
    //当prefix_len==0 则说明没有匹配的 前缀 后缀 则将next[i]=0 重新开始
    while(i<s.size())
    {
        if(s[prefix_len]==s[i])
        {
            prefix_len++;
            next.push_back(prefix_len);
            i++;
        }
        else
        {
            if (prefix_len==0)
            {
                next.push_back(0);
                i++;
            }
            else
            {
                prefix_len=next[prefix_len-1];
            }
        }
    }
    return next;
}
int main()
{
    //利用next数组 来跳过对应长度的字符串 进行效率更高的字符串匹配 即KMP算法
    string s;
    string patt;
    cin>>s>>patt;
    vector<int> next=comp_next(patt);
    int i=0;//s的索引
    int j=0;//模式串的索引
    //重点 ： i 永不回退 从而优化匹配算法
    while (i<s.size())
    {
        if (s[i]==patt[j])
        {
            i++;
            j++;
        }
        else if (j==0)
        {
            i++;    //上来就失配
        }
        else
        {
            j=next[j-1];    //其余失配情况 j回退next数组对应位置
        }
        if (j==patt.size())
        {
            cout<<i-j+1<<endl;
            j=next[j-1];    //继续寻找下一个匹配
        }
    }
    for (int i=0;i<next.size();i++)
    {
        cout<<next[i];
        if (i!=next.size()-1)
        {
            cout<<" ";
        }
    }
    return 0;
}