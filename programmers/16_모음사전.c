/*
 * 16. 모음사전
 * https://school.programmers.co.kr/learn/courses/30/lessons/84512
 * 아이디어: 사전을 하나씩 만들지 않고 "몇 번째인지"를 계산한다.
 *           i번째 자리 글자가 한 칸 뒤로 가면 그 아래 가능한 단어 수(size)만큼 순서가 밀린다.
 *           size[5]=1, size[4]=6, size[3]=31, size[2]=156, size[1]=781
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int solution(const char* s) {
    int len = strlen(s);
    int result = len;

    int size[6];
    size[5] = 1;

    for (int i = 4; i >= 1; i--) {
        size[i] = size[i + 1] * 5 + 1;
    }

    for (int i = 0; i < len; i++) {
        int idx = 0;
        for (int j = 0; j < 5; j++) {
            if (s[i] == "AEIOU"[j]) {
                idx = j;
                break;
            }
        }
        result += idx * size[i + 1];
    }
    return result;
}
