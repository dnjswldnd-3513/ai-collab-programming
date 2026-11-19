/*
 * 9. 약수의 개수와 덧셈
 * https://school.programmers.co.kr/learn/courses/30/lessons/77884
 * 아이디어: left~right 각 수의 약수를 직접 센다. 개수가 짝수면 더하고 홀수면 뺀다.
 */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int left, int right) {
    int result = 0;
    for (int i = left; i <= right; i++) {
        int count = 0;
        for (int j = 1; j <= i; j++) {
            if (i % j == 0) count++;
        }
        if (count % 2 == 0) {
            result += i;
        } else {
            result -= i;
        }
    }

    return result;
}
