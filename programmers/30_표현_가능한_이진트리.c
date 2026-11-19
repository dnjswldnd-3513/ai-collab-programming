/*
 * 30. 표현 가능한 이진트리
 * https://school.programmers.co.kr/learn/courses/30/lessons/150367
 * 아이디어: 1) 수를 이진수로 바꾸고, 앞에 0을 채워 길이를 포화 이진트리 크기(1, 3, 7, 15, ... = 2^k - 1)로 맞춘다.
 *           2) 가운데 글자가 루트, 왼쪽 절반이 왼쪽 서브트리, 오른쪽 절반이 오른쪽 서브트리(재귀).
 *           3) 루트가 '0'(더미 노드)인데 그 아래에 '1'(실제 노드)이 있으면 표현 불가능.
 *           모든 서브트리가 통과하면 1, 아니면 0.
 */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

static bool check(const char* bit, int l, int r) {

    if (l > r) {
        return true;
    }
    if (l == r) {
        return true;
    }

    int mid = (l + r) / 2;

    if (bit[mid] == '0') {

        for (int i = l; i <= r; i++) {
            if (bit[i] == '1') {
                return false;
            }
        }
        return true;
    }

    return check(bit, l, mid - 1) && check(bit, mid + 1, r);
}

int* solution(long long numbers[], size_t len) {

    int* result = (int*)malloc(sizeof(int) * len);

    for (size_t i = 0; i < len; i++) {
        long long v = numbers[i];

        int need = 0;

        for (long long t = v; t > 0; t >>= 1) {
            need++;
        }

        if (need == 0) {
            need = 1;
        }

        int len = 1;

        while (len < need) {
            len = len * 2 + 1;
        }

        char bit[64];
        for (int j = len - 1; j >= 0; j--) {

            bit[j] = (char)('0' + (int)(v & 1LL));
            v >>= 1;
        }

        result[i] = check(bit, 0, len - 1) ? 1 : 0;
    }

    return result;
}
