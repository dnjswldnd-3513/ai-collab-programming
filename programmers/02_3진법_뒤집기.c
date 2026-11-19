/*
 * 2. 3진법 뒤집기
 * https://school.programmers.co.kr/learn/courses/30/lessons/68935
 * 아이디어: n을 3으로 나눈 나머지를 차례로 모으면 이미 "뒤집힌 3진법"이 된다.
 *           그 자리들을 앞에서부터 다시 10진수로 조립한다.
 */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n) {
    int arr[20];
    int count = 0;

    while (n > 0) {
        arr[count++] = n % 3;
        n /= 3;
    }

    int result = 0;

    for (int i = 0; i < count; i++) {
        result = result * 3 + arr[i];
    }
    return result;
}
