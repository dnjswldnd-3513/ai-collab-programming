/*
 * 17. 가장 큰 수
 * https://school.programmers.co.kr/learn/courses/30/lessons/42746
 * 아이디어: 숫자를 문자열로 바꾸고, 두 수 a, b 중 "ab"와 "ba" 중 더 큰 쪽이 되도록 정렬한다.
 *           예) 3과 30 → "330" > "303" 이므로 3이 앞.
 *           모두 0이면 "000"이 아니라 "0"을 돌려준다.
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int cmp(const void* a, const void* b) {
    char x[24], y[24];
    sprintf(x, "%s%s", *(char**)a, *(char**)b);
    sprintf(y, "%s%s", *(char**)b, *(char**)a);
    return strcmp(y, x);
}

char* solution(int num[], size_t len) {
    char** s = malloc(len * sizeof(char*));
    char* result = calloc(len * 12 + 1, 1);

    for (size_t i = 0; i < len; i++) {
        sprintf(s[i] = malloc(12), "%d", num[i]);
    }
    qsort(s, len, sizeof(char*), cmp);
    for (size_t i = 0; i < len; i++) {
        strcat(result, s[i]);
    }

    return result[0] == '0' ? strcpy(result, "0") : result;
}
