/*
 * 18. 큰 수 만들기
 * https://school.programmers.co.kr/learn/courses/30/lessons/42883
 *
 * 주의: LMS "17, 18" 글의 18번 자리에는 아래처럼 19번(피로도) 코드가 올라가 있다.
 *       큰 수 만들기는 solution(const char* number, int k) 형태라 이 코드로는 풀리지 않는다.
 *       원래 풀이 방법은 정리.md 18번 항목 참고.
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>

int dg[8][2], n, best;

void dfs(int visited, int st, int cnt) {
    if (cnt > best) {
        best = cnt;
    }
    for (int i = 0; i < n; i++) {
        if (!(visited & (1 << i)) && st >= dg[i][0]) {
            dfs(visited | (1 << i), st - dg[i][1], cnt + 1);
        }
    }
}

int solution(int st, int** dun, size_t row, size_t col) {
    n = (int)row;
    for (int i = 0; i < n; i++) {
        dg[i][0] = dun[i][0];
        dg[i][1] = dun[i][1];
    }
    best = 0;
    dfs(0, st, 0);
    return best;
}
