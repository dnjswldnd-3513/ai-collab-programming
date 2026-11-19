/*
 * 10. 없는 숫자 더하기
 * https://school.programmers.co.kr/learn/courses/30/lessons/86051
 * 아이디어: 0~9 중 "있음" 표시 배열을 만들고, 표시가 없는 숫자만 더한다.
 */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int arr[], size_t len) {
    bool asdf[20] = {false};
    int result = 0;

    for (size_t i = 0; i < len; i++) {
        asdf[arr[i]] = true;
    }

    for (int i = 0; i < 10; i++) {
        if (!asdf[i]) {
            result += i;
        }
    }
    return result;
}
