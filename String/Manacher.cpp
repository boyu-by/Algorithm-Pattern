// Manacher算法实现，计算字符串中每个位置的最长回文串长度

#include <bits/stdc++.h>
using namespace std;
vector<int> manacher(string s) {
    // 预处理字符串
    string processed = "^";
    for (char c : s) {
        processed += "#";
        processed += c;
    }
    processed += "#$";
    
    int n = processed.length();
    vector<int> P(n, 0);  // 回文半径数组
    int center = 0, right = 0;  // 当前最右回文的中心和右边界
    
    for (int i = 1; i < n - 1; i++) {
        // 利用对称性获取初始回文半径
        if (i < right) {
            P[i] = min(right - i, P[2 * center - i]);
        }
        
        // 尝试扩展回文
        while (processed[i + P[i] + 1] == processed[i - P[i] - 1]) {
            P[i]++;
        }
        
        // 更新最右回文边界
        if (i + P[i] > right) {
            center = i;
            right = i + P[i];
        }
    }
    
    return P;
}

int main()
{
    string s;
    cin >> s;
    vector<int> P = manacher(s);
    int max_len = 0;
    for (int i = 0; i < P.size() - 1; i++)
    {
        max_len = max(max_len, P[i]);
    }
    cout << max_len << endl;
    return 0;
}

