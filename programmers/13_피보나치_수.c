/*
 * 13. 피보나치 수
 * https://school.programmers.co.kr/learn/courses/30/lessons/12945
 * 아이디어: dp[i] = dp[i-1] + dp[i-2] 를 앞에서부터 채운다(동적 계획법).
 *           수가 너무 커지므로 매번 1234567로 나눈 나머지만 저장한다.
 */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n) {
    long long dp[100001];

    int asdf = 1234567;
    dp[0] = 0;

    if (n >= 1) {
        dp[1] = 1;
    }

    for (int i = 2; i <= n; i++) {
        long long sum = dp[i - 1] + dp[i - 2];
        long long res = sum % asdf;
        dp[i] = res;
    }

    int result = dp[n];
    return result;
}
