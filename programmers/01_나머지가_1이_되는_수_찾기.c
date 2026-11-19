/*
 * 1. 나머지가 1이 되는 수 찾기
 * https://school.programmers.co.kr/learn/courses/30/lessons/87389
 * 아이디어: 2부터 하나씩 올라가며 n % i == 1 인 첫 번째 i를 찾으면 그게 가장 작은 답이라 바로 멈춘다.
 *           (1은 모든 수를 나머지 0으로 나누므로 2부터 시작)
 */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n) {
    int result = 0;

    for (int i = 2; i < n; i++) {

        if (n % i == 1) {
            result = i;
            break;
        }
    }

    return result;
}
