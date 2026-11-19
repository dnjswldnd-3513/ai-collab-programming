/*
 * 21. 숫자 게임
 * https://school.programmers.co.kr/learn/courses/30/lessons/12987
 * 아이디어: A팀, B팀 모두 오름차순 정렬. B의 작은 수부터 보면서
 *           지금 A의 가장 작은 남은 수(a[i])를 이길 수 있으면 그 판을 이기고 다음 A로 넘어간다.
 *           못 이기는 B 카드는 버리는 판에 쓴다(그리디).
 */
#include <stdio.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int solution(int a[], size_t lena, int b[], size_t lenb) {
    int result = 0;
    int i = 0;
    int n = (int)lena;
    qsort(a, n, sizeof(int), cmp);
    qsort(b, n, sizeof(int), cmp);

    for (int j = 0; j < n; j++) {
        if (b[j] > a[i]) {
            result++;
            i++;
        }
    }
    return result;
}
