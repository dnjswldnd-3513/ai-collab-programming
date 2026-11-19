/*
 * 28. 110 옮기기
 * https://school.programmers.co.kr/learn/courses/30/lessons/77886
 * 아이디어: 1) 스택처럼 글자를 쌓다가 맨 위 3개가 "110"이 되면 빼내고 개수(cnt)를 센다.
 *              → 남은 문자열에는 "110"이 없다.
 *           2) 남은 문자열에서 맨 뒤에 붙은 '1'들 바로 앞(split)에 "110"을 cnt번 끼워 넣는다.
 *              ("110"은 "111"보다 앞에 와야 사전순으로 작고, "0"보다는 뒤에 와야 작기 때문)
 *           3) 남은 자리는 원래 맨 뒤에 있던 '1'로 채운다.
 */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char** solution(const char* s[], size_t s_len) {

    char** result = (char**)malloc(sizeof(char*) * s_len);

    if (result == NULL) {
        return NULL;
    }

    for (size_t i = 0; i < s_len; i++) {
        const char* str = s[i];
        size_t len = strlen(str);
        char* res = (char*)malloc(len + 1);

        if (res == NULL) {
            return NULL;
        }

        size_t top = 0;
        size_t cnt = 0;

        for (size_t j = 0; j < len; j++) {
            char c = str[j];
            res[top++] = c;

            if (c == '0' && top >= 3 && res[top - 2] == '1' && res[top - 3] == '1') {
                top -= 3;
                cnt++;
            }
        }

        size_t split = top;
        while (split > 0 && res[split - 1] == '1') {
            split--;
        }

        size_t p = split;

        for (size_t k = 0; k < cnt; k++) {
            res[p++] = '1';
            res[p++] = '1';
            res[p++] = '0';
        }

        while (p < len) {
            res[p++] = '1';
        }

        res[len] = '\0';

        result[i] = res;
    }

    return result;
}
