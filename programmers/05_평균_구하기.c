/*
 * 5. 평균 구하기
 * https://school.programmers.co.kr/learn/courses/30/lessons/12944
 * 아이디어: 전부 더해서 개수로 나눈다. 소수점이 필요해서 합을 double로 둔다.
 */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int arr[], size_t len) {
    double sum = 0;

    for (int i = 0; i < len; i++) {
        sum += arr[i];
    }

    double result = sum / len;

    return result;
}
