/*
 * 25. 부대복귀
 * https://school.programmers.co.kr/learn/courses/30/lessons/132266
 * 아이디어: 부대원마다 BFS를 돌리면 느리다. 길이 양방향이므로 거꾸로 "목적지(destination)에서 한 번만" BFS를 돌려
 *           모든 지역까지의 최단 거리를 구하고, sources 위치의 거리를 꺼낸다. 못 가는 곳은 -1.
 *           그래프는 인접 리스트를 배열로 만든 형태(head/nxt/to)로 저장한다.
 *           head[a] = a에서 나가는 첫 간선 번호, nxt[e] = 같은 지점에서 나가는 다음 간선, to[e] = 간선 e가 가는 곳.
 */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(int n, int** roads, size_t roads_rows, size_t roads_cols, int sources[], size_t sources_len, int destination) {

    int m = (int)roads_rows;
    int* head = (int*)malloc(sizeof(int) * (n + 1));
    int* nxt = (int*)malloc(sizeof(int) * (2 * m));
    int* to = (int*)malloc(sizeof(int) * (2 * m));

    for (int i = 1; i <= n; i++) {
        head[i] = -1;
    }

    int edgeCount = 0;

    for (int i = 0; i < m; i++) {
        int a = roads[i][0];
        int b = roads[i][1];
        to[edgeCount] = b; nxt[edgeCount] = head[a]; head[a] = edgeCount; edgeCount++;
        to[edgeCount] = a; nxt[edgeCount] = head[b]; head[b] = edgeCount; edgeCount++;
    }

    int* dist = (int*)malloc(sizeof(int) * (n + 1));

    for (int i = 1; i <= n; i++) {
        dist[i] = -1;
    }

    int* queue = (int*)malloc(sizeof(int) * n);
    int qh = 0, qt = 0;

    dist[destination] = 0;
    queue[qt++] = destination;

    while (qh < qt) {
        int cur = queue[qh++];
        for (int e = head[cur]; e != -1; e = nxt[e]) {
            int nxtNode = to[e];
            if (dist[nxtNode] == -1) {
                dist[nxtNode] = dist[cur] + 1;
                queue[qt++] = nxtNode;
            }
        }
    }
    int* answer = (int*)malloc(sizeof(int) * sources_len);

    for (int i = 0; i < (int)sources_len; i++) {
        answer[i] = dist[sources[i]];
    }

    free(head); free(nxt); free(to); free(dist); free(queue);
    return answer;
}
