/*
 * 6. 짝수와 홀수
 * https://school.programmers.co.kr/learn/courses/30/lessons/12937
 * 아이디어: n % 2 로 짝홀을 가르고, 돌려줄 문자열은 malloc으로 만든다.
 *           ("Even"은 4글자 + 끝 표시 '\0' 1칸 = 5칸)
 */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char* solution(int n) {
    char* result;

    if (n % 2 == 0) {
        result = malloc(sizeof(char) * 5);
        strcpy(result, "Even");
    } else {
        result = malloc(sizeof(char) * 5);
        strcpy(result, "Odd");
    }

    return result;
}
