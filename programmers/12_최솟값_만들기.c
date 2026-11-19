/*
 * 12. 최솟값 만들기
 * https://school.programmers.co.kr/learn/courses/30/lessons/12941
 * 아이디어: 가장 작은 수 x 가장 큰 수를 짝지어야 곱의 합이 최소.
 *           a는 오름차순, b는 내림차순으로 정렬한 뒤 같은 위치끼리 곱한다.
 */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int asc(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}
int desc(const void* a, const void* b) {
    return (*(int*)b - *(int*)a);
}

int solution(int a[], size_t lena, int b[], size_t lenb) {
    qsort(a, lena, sizeof(int), asc);
    qsort(b, lenb, sizeof(int), desc);
    long long result = 0;

    for (int i = 0; i < lena; i++) {
        int aa = a[i];
        int bb = b[i];
        result += aa * bb;
    }
    return result;
}
