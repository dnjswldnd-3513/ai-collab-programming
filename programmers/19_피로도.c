/*
 * 19. 피로도
 * https://school.programmers.co.kr/learn/courses/30/lessons/87946
 * 아이디어: 던전이 최대 8개라 모든 순서를 다 해 봐도 된다(완전 탐색, DFS).
 *           방문한 던전은 비트마스크 vis로 표시한다. (i번째 비트가 1이면 i번 던전은 이미 감)
 *           현재 피로도 st가 최소 필요 피로도 이상인 던전만 들어가고, 가장 많이 돈 횟수를 best에 남긴다.
 */
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>

int dg[8][2], n, best;

void dfs(int vis, int st, int cnt) {
    if (cnt > best) {
        best = cnt;
    }
    for (int i = 0; i < n; i++) {
        if (!(vis & (1 << i)) && st >= dg[i][0]) {
            dfs(vis | (1 << i), st - dg[i][1], cnt + 1);
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
