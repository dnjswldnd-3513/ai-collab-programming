/*
 * 20. 전력망을 둘로 나누기
 * https://school.programmers.co.kr/learn/courses/30/lessons/86971
 * 아이디어: 전선을 하나씩 끊어 본다. 끊은 뒤 한쪽 끝(a)에서 DFS로 연결된 송전탑 수(cnt)를 세면
 *           나머지는 n - cnt. 두 쪽 차이 |cnt - (n - cnt)| = |2*cnt - n| 의 최솟값이 답.
 *           다 센 뒤에는 끊은 전선을 다시 이어 놓는다.
 */
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int adj[101][101], n;
bool visited[101];

int dfs(int cur) {
    visited[cur] = true;

    int count = 1;
    for (int next = 1; next <= n; next++)
        if (adj[cur][next] && !visited[next])
            count += dfs(next);
    return count;
}

int solution(int n_, int** wires, size_t row, size_t col) {
    n = n_;
    memset(adj, 0, sizeof(adj));
    for (int i = 0; i < (int)row; i++)
        adj[wires[i][0]][wires[i][1]] = adj[wires[i][1]][wires[i][0]] = 1;

    int best = n;
    for (int i = 0; i < (int)row; i++) {
        int a = wires[i][0], b = wires[i][1];
        adj[a][b] = adj[b][a] = 0;
        memset(visited, 0, sizeof(visited));
        int diff = abs(2 * dfs(a) - n);
        if (diff < best) best = diff;
        adj[a][b] = adj[b][a] = 1;
    }
    return best;
}
