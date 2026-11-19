/*
 * 14. 멀리 뛰기
 * https://school.programmers.co.kr/learn/courses/30/lessons/12914
 * 아이디어: n칸에 도착하는 방법 = (n-1칸에서 1칸) + (n-2칸에서 2칸).
 *           피보나치와 같은 점화식이고 시작값만 dp[0]=1, dp[1]=1 로 다르다.
 */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

long long solution(int n) {

    long long dp[2001];
    int asdf = 1234567;

    dp[0] = 1;
    if (n >= 1) {
        dp[1] = 1;
    }

    for (int i = 2; i <= n; i++) {
        long long sum = dp[i - 1] + dp[i - 2];
        long long res = sum % asdf;
        dp[i] = res;
    }

    long long result = dp[n];
    return result;
}
