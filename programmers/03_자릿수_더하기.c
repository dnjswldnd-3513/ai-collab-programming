/*
 * 3. 자릿수 더하기
 * https://school.programmers.co.kr/learn/courses/30/lessons/12931
 * 아이디어: % 10 으로 마지막 자리를 꺼내 더하고, / 10 으로 그 자리를 지운다.
 */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n) {
    int result = 0;

    while (n > 0) {
        result += n % 10;
        n /= 10;
    }

    return result;
}
