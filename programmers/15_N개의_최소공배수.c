/*
 * 15. N개의 최소공배수
 * https://school.programmers.co.kr/learn/courses/30/lessons/12953
 * 아이디어: lcm(a, b) = a / gcd(a, b) * b. 앞에서부터 하나씩 누적해서 최소공배수를 구한다.
 *           gcd는 유클리드 호제법(나머지를 반복해서 구함).
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int solution(int arr[], size_t len) {
    long long result = arr[0];

    for (int i = 1; i < len; i++) {
        int curr = arr[i];
        int g = gcd(result, curr);

        long long sum = result / g;
        long long res = sum * curr;
        result = res;
    }
    return result;
}
