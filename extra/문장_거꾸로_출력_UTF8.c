/*
 * LMS "13" 글 (2026-10-28)
 * 프로그래머스 문제가 아니라 콘솔 입력을 받는 별도 실습으로 보인다. (프로그래머스 13번 피보나치 수는 programmers 폴더)
 * 아이디어: 문장 끝으로 포인터를 옮긴 뒤 한 글자씩 거꾸로 출력한다.
 *           한글은 UTF-8에서 3바이트라 바이트 단위로 뒤집으면 글자가 깨진다.
 *           10xxxxxx(= & 0xC0 == 0x80) 바이트는 글자의 중간 바이트이므로, 글자의 첫 바이트까지 앞으로 더 간 다음
 *           그 글자 한 덩어리는 원래 순서대로 출력한다.
 */
#include <stdio.h>

int main(void)
{
    char str[256];
    char *p, *start, *q;

    printf("문장을 입력하세요: ");
    fflush(stdout); /* 입력 전에 안내문이 먼저 보이도록 */
    fgets(str, sizeof(str), stdin);

    p = str;
    while (*p != '\0' && *p != '\n') /* 문장의 끝까지 포인터 이동 */
        p++;
    *p = '\0'; /* fgets가 넣은 줄바꿈 제거 */

    printf("역순 출력: ");
    while (p > str) { /* 끝에서 처음까지 한 글자씩 거꾸로 */
        start = p - 1;
        /* 한글은 UTF-8로 3바이트: 10xxxxxx 바이트는 글자의 중간이므로 앞으로 더 이동 */
        while (start > str && (*(unsigned char *)start & 0xC0) == 0x80)
            start--;
        for (q = start; q < p; q++) /* 글자 하나(1~4바이트)는 원래 순서대로 출력 */
            putchar(*q);
        p = start;
    }
    putchar('\n');

    return 0;
}
