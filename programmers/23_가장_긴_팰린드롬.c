/*
 * 23. 가장 긴 팰린드롬
 * https://school.programmers.co.kr/learn/courses/30/lessons/12904
 * 아이디어: 매내처(Manacher) 알고리즘.
 *           1) "abba" → "#a#b#b#a#" 처럼 글자 사이에 #을 넣어 짝수·홀수 길이를 한 번에 다룬다.
 *           2) p[i] = i를 중심으로 양쪽으로 늘릴 수 있는 반지름.
 *           3) 이미 찾은 가장 오른쪽 팰린드롬(center, right) 안이라면
 *              거울 위치(2*center - i)의 값을 재활용해서 처음부터 다시 비교하지 않는다.
 *           #을 넣은 문자열에서의 반지름 p[i]가 원래 문자열의 팰린드롬 길이와 같다.
 */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int solution(const char* s) {
    int len = strlen(s);

    if (len == 0) return 0;

    int t_len = 2 * len + 1;

    char* t = (char*)malloc(t_len + 1);

    for (int i = 0; i < t_len; i++) {
        t[i] = (i % 2 == 0) ? '#' : s[i / 2];
    }
    t[t_len] = '\0';

    int* p = (int*)calloc(t_len, sizeof(int));
    int center = 0, right = 0;
    int max_len = 0;

    for (int i = 0; i < t_len; i++) {

        if (i < right) {
            p[i] = (right - i < p[2 * center - i]) ? (right - i) : p[2 * center - i];
        }
        while (i - p[i] - 1 >= 0 && i + p[i] + 1 < t_len && t[i - p[i] - 1] == t[i + p[i] + 1])
            p[i]++;

        if (i + p[i] > right) {
            center = i;
            right = i + p[i];
        }

        if (p[i] > max_len) {
            max_len = p[i];
        }
    }

    free(t);
    free(p);
    return max_len;
}
