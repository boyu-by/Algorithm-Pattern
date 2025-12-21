#include <bits/stdc++.h>
using namespace std;

// 快速幂算法 - 计算 a^b mod m
long long fastPower(long long base, long long exponent, long long mod) {
    long long result = 1;
    base %= mod;
    
    while (exponent > 0) {
        // 如果指数是奇数，将当前base乘入结果
        if (exponent & 1) {
            result = (result * base) % mod;
        }
        // base自乘，指数右移一位
        base = (base * base) % mod;
        exponent >>= 1;
    }
    
    return result;
}

// 不带模运算的快速幂
long long fastPower(long long base, long long exponent) {
    long long result = 1;
    
    while (exponent > 0) {
        if (exponent & 1) {
            result *= base;
        }
        base *= base;
        exponent >>= 1;
    }
    
    return result;
}

int main() {
    long long a, b, p;
    cin >> a >> b >> p;
    cout << a << "^" << b << " mod " << p << "=" << fastPower(a, b, p) << endl;
    return 0;
}