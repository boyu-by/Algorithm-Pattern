#include <bits/stdc++.h>
using namespace std;
const int N = 10086;
int a[N], b[N], c[N];

// 比较函数，用于判断 a 是否大于等于 b
bool cmp(int a[], int b[], int n, int m) {
    if (n > m) return true;   // a 的位数比 b 多，则 a > b
    if (n < m) return false;  // a 的位数比 b 少，则 a < b
    // 位数相同，从高位开始比较
    for (int i = n; i >= 1; i--) {
        if (a[i] > b[i]) return true;
        if (a[i] < b[i]) return false;
    }
    return true; // 相等的情况也认为是 a >= b
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.length();
    int m = s2.length();

    // 将字符串存储到数组中 注意逆序存储
    for (int i = 0; i < n; i++) {
        a[n - i] = s1[i] - '0';
    }
    for (int i = 0; i < m; i++) {
        b[m - i] = s2[i] - '0';
    }

    bool flag = cmp(a, b, n, m); // 判断 a 和 b 的大小关系
    
    // 进行减法运算
    int len = max(n, m);
    
    if (flag) { // |a| >= |b|, 正常做减法
        for (int i = 1; i <= len; i++) {
            c[i] += a[i] - b[i];
            if (c[i] < 0) {      // 如果当前位不够减，向前借位
                c[i] += 10;
                c[i + 1] -= 1;
            }
        }
    } else { // |a| < |b|, 结果为负数，交换操作数再计算，并标记负号
        for (int i = 1; i <= len; i++) {
            c[i] += b[i] - a[i];
            if (c[i] < 0) {      // 如果当前位不够减，向前借位
                c[i] += 10;
                c[i + 1] -= 1;
            }
        }
    }

    // 去除前导零
    while (len > 1 && c[len] == 0) len--;

    // 输出结果
    if (!flag && !(len == 1 && c[1] == 0)) { // 只有当结果不是0时才输出负号
        cout << "-";
    }
    for (int i = len; i >= 1; i--) {
        cout << c[i];
    }
    return 0;
}