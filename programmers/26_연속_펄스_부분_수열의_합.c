/*
 * 26. 연속 펄스 부분 수열의 합
 * https://school.programmers.co.kr/learn/courses/30/lessons/161988
 * 아이디어: 펄스 [1,-1,1,...]를 곱한 수열의 누적합 curr를 구한다.
 *           구간합 = 누적합끼리의 차이이므로, (누적합 최댓값 - 누적합 최솟값)이 가장 큰 구간합이다.
 *           펄스 [-1,1,-1,...]은 부호만 반대라 같은 값(max - min)이 나와서 한 번만 계산하면 된다.
 *           max, min을 0에서 시작하는 건 "맨 앞부터 시작하는 구간"도 포함하기 위해서.
 */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

long long solution(int a[], size_t len) {
    int n = (int)len;
    long long curr = 0;
    long long max = 0;
    long long min = 0;

    for (int i = 0; i < n; i++) {
        long long var;
        if (i % 2 == 0) {
            var = a[i];
        } else {
            var = -a[i];
        }

        curr += var;

        if (curr < min) {
            min = curr;
        }
        if (curr > max) {
            max = curr;
        }
    }

    long long result = max - min;
    return result;
}
