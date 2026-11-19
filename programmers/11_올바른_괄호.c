/*
 * 11. 올바른 괄호
 * https://school.programmers.co.kr/learn/courses/30/lessons/12909
 * 아이디어: '('면 +1, ')'면 -1. 중간에 음수가 되면 짝 없는 ')'가 먼저 나온 것이라 실패.
 *           끝까지 갔을 때 0이면 성공.
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool solution(const char* s) {
    int len = strlen(s);
    int result = 0;

    for (int i = 0; i < len; i++) {
        if (s[i] == '(') {
            result++;
        } else {
            result--;
        }
        if (result < 0) {
            return false;
        }
    }
    if (result == 0) {
        return true;
    }
}
