/*
 * 7. 정수 제곱근 판별
 * https://school.programmers.co.kr/learn/courses/30/lessons/12934
 * 아이디어: sqrt로 제곱근 후보 x를 구하고, 실수 오차를 while 두 줄로 보정한다.
 *           x*x == n 이면 (x+1)^2, 아니면 -1.
 */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

long long solution(long long n) {
    long long x = sqrt((double)n);
    long long y;

    while (x * x > n) x--;
    while ((x + 1) * (x + 1) <= n) x++;
    while (x * x == n) {
        y = x + 1;
        return y * y;
    }
    return -1;
}
