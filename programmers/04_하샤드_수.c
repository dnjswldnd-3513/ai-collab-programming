/*
 * 4. 하샤드 수
 * https://school.programmers.co.kr/learn/courses/30/lessons/12947
 * 아이디어: 자릿수 합을 구한 뒤(3번과 같은 방법) n이 그 합으로 나누어떨어지는지 본다.
 *           n을 직접 쪼개면 원래 값이 사라지므로 복사본 nn을 쪼갠다.
 */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n) {
    int sum = 0;
    int nn = n;

    while (nn > 0) {
        sum += nn % 10;
        nn /= 10;
    }

    bool asdf = (n % sum == 0);
    return asdf;
}
