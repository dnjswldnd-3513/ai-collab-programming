/*
 * 27. 인사고과
 * https://school.programmers.co.kr/learn/courses/30/lessons/152995
 * 아이디어: 근무 태도(a) 내림차순, 같으면 동료 평가(b) 오름차순으로 정렬한다.
 *           그러면 앞에서부터 보면서 "지금까지 본 b의 최댓값(maxb)"보다 b가 작으면
 *           a도 b도 둘 다 더 높은 사람이 앞에 있다는 뜻 → 인센티브 탈락.
 *           완호(첫 번째 사원)가 탈락이면 -1, 아니면 완호보다 합이 큰 사람 수 + 1이 석차.
 *           (a가 같을 때 b를 오름차순으로 두는 이유: a가 같은 사람끼리는 서로 탈락시키면 안 되기 때문)
 */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct {
    int a, b;
} P;

static int cmp(const void* x, const void* y) {
    const P* p = (const P*)x, * q = (const P*)y;

    if (p->a != q->a) {
        return q->a - p->a;
    }
    return p->b - q->b;
}

int solution(int** scores, size_t rows, size_t cols) {
    int wa = scores[0][0];
    int wb = scores[0][1];
    int wsum = wa + wb;

    P* arr = (P*)malloc(sizeof(P) * rows);

    for (size_t i = 0; i < rows; i++) {
        arr[i].a = scores[i][0];
        arr[i].b = scores[i][1];
    }

    qsort(arr, rows, sizeof(P), cmp);

    int maxb = -1, rank = 1;
    bool ok = true;

    for (size_t i = 0; i < rows; i++) {
        if (arr[i].b < maxb) {
            if (arr[i].a == wa && arr[i].b == wb) {
                ok = false; break;
            }
            continue;
        }

        maxb = arr[i].b;
        if (arr[i].a + arr[i].b > wsum) {
            rank++;
        }
    }

    free(arr);
    return ok ? rank : -1;
}
