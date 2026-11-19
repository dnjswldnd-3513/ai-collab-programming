/*
 * 22. 다단계 칫솔 판매
 * https://school.programmers.co.kr/learn/courses/30/lessons/77486
 * 아이디어: 판매 기록마다 판매자에서 시작해 추천인을 따라 위로 올라간다.
 *           각 단계에서 10%는 위로 넘기고 나머지 90%(profit - profit/10)를 자기 몫으로 갖는다.
 *           추천인이 "-"(센터)이거나 넘길 돈이 0원이 되면 멈춘다.
 */
#include <stdlib.h>
#include <string.h>

static int find_index(const char* names[], int n, const char* name) {
    for (int i = 0; i < n; i++) {
        if (!strcmp(names[i], name)) {
            return i;
        }
    }
    return -1;
}

int* solution(const char* enroll[], size_t enroll_len, const char* referral[], size_t referral_len,
              const char* seller[], size_t seller_len, int amount[], size_t amount_len) {
    int n = (int)enroll_len;
    long long* earnings = calloc(n, sizeof(long long));

    for (int s = 0; s < (int)seller_len; s++) {
        long long profit = (long long)amount[s] * 100;
        for (int idx = find_index(enroll, n, seller[s]);
             idx != -1 && profit > 0;
             idx = strcmp(referral[idx], "-") ? find_index(enroll, n, referral[idx]) : -1, profit /= 10)
        {
            earnings[idx] += profit - profit / 10;
        }
    }

    int* answer = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        answer[i] = (int)earnings[i];
    }
    free(earnings);
    return answer;
}
