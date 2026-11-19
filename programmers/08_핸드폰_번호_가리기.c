/*
 * 8. 핸드폰 번호 가리기
 * https://school.programmers.co.kr/learn/courses/30/lessons/12948
 * 아이디어: 새 문자열을 만들어 뒤 4자리 전까지는 '*', 뒤 4자리는 원래 글자를 넣는다.
 */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char* solution(const char* number) {
    int len = strlen(number);
    char* result = malloc(len + 1);

    for (int i = 0; i < len; i++) {
        if (i < len - 4) {
            result[i] = '*';
        } else {
            result[i] = number[i];
        }
    }
    result[len] = '\0';
    return result;
}
