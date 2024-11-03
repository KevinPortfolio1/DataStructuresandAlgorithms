//動態規劃（Dynamic Programming, DP）是一種解決問題的算法設計技術，
//通常用於最優化問題，特別是在重疊子問題和最優子結構的情況下
#include <iostream>
#include <vector>

using namespace std;

// 計算第 n 個 Fibonacci 數
int fibonacci(int n) {
    if (n <= 1) return n;

    // 建立一個數組來保存已計算的 Fibonacci 數
    vector<int> dp(n + 1);
    dp[0] = 0; // F(0) = 0
    dp[1] = 1; // F(1) = 1

    // 逐步計算 F(2) 到 F(n)
    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int main() {
    int n;
    cout << "輸入 n: ";
    cin >> n;

    cout << "Fibonacci(" << n << ") = " << fibonacci(n) << endl;

    return 0;
}