/*
 * 29. 미로 탈출 명령어
 * https://school.programmers.co.kr/learn/courses/30/lessons/150365
 * 아이디어: 사전순으로 가장 빠른 경로 = 매 걸음마다 d < l < r < u 순서로 가능한 방향을 먼저 고른다(그리디).
 *           "그 칸으로 가도 남은 걸음 수로 도착할 수 있나?"를 reachable로 확인한다.
 *           - 남은 거리(맨해튼 거리)가 남은 걸음 이하여야 하고
 *           - (남은 걸음 - 거리)가 짝수여야 한다. (한 번 갔다 오면 2걸음씩 쓰므로)
 *           시작부터 불가능하면 "impossible".
 */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

static int iabs(int v) {
    return v < 0 ? -v : v;
}

static bool reachable(int x, int y, int r, int c, int rem) {
    int dist = iabs(x - r) + iabs(y - c);
    return dist <= rem && (rem - dist) % 2 == 0;
}

char* solution(int n, int m, int x, int y, int r, int c, int k) {

    if (!reachable(x, y, r, c, k)) {

        char* imp = (char*)malloc(11);
        strcpy(imp, "impossible");
        return imp;
    }

    char* result = (char*)malloc(k + 1);

    const char dir[4] = {'d', 'l', 'r', 'u'};
    const int dx[4] = { 1, 0, 0, -1};
    const int dy[4] = { 0, -1, 1, 0};

    int cx = x, cy = y;

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < 4; j++) {

            int nx = cx + dx[j], ny = cy + dy[j];

            if (nx < 1 || nx > n || ny < 1 || ny > m) {
                continue;
            }
            if (!reachable(nx, ny, r, c, k - i - 1)) {
                continue;
            }
            result[i] = dir[j];
            cx = nx; cy = ny;

            break;
        }
    }

    result[k] = '\0';

    return result;
}
