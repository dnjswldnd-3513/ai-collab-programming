/*
 * 24. 풍선 터트리기
 * https://school.programmers.co.kr/learn/courses/30/lessons/68646
 * 아이디어: 풍선 하나가 끝까지 남으려면 "왼쪽 전체의 최솟값보다 작거나" "오른쪽 전체의 최솟값보다 작아야" 한다.
 *           (작은 풍선 터뜨리기 찬스를 한 번만 쓸 수 있으므로, 양쪽 모두에 자기보다 작은 게 있으면 탈락)
 *           1) 왼쪽→오른쪽: 지금까지의 최솟값을 새로 갱신하는 풍선을 센다. 마지막 갱신 위치 last = 전체 최솟값 위치.
 *           2) 오른쪽→왼쪽: 같은 방법으로 세되, 전체 최솟값(last)은 이미 셌으니 빼고 센다.
 */
#include <stddef.h>

int solution(int a[], size_t len) {
    int n = (int)len;
    int count = 1;
    int far = a[0];
    int last = 0;

    for (int i = 1; i < n; i++) {
        if (a[i] < far) {
            far = a[i];
            last = i;
            count++;
        }
    }

    far = a[n - 1];
    if (last != n - 1) {
        count++;
    }

    for (int i = n - 2; i >= 0; i--) {
        if (a[i] < far) {
            far = a[i];
            if (i != last) {
                count++;
            }
        }
    }
    return count;
}
