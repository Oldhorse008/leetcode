#include <stdio.h>
#include <string.h>

int longestPalindrome(char *s) {
    int ans = 0;
    int leng = strlen(s);
    int count[128]; // 有128个字符

    for (int i = 0; i < 128; i++) {
        count[i] = 0;
    }

    for (int i = 0; i < leng; i++) {
        count[(int)s[i]]++; // 直接使用ASCLL码的位数计数
    }

    for (int i = 0; i < sizeof(count) / sizeof(count[0]); i++) {
        ans += count[i] / 2 * 2;
        if ((ans % 2 == 0) && (count[i] % 2 != 0)) {
            ans += 1;
        }
    }

    return ans;
}

int main() {
    char a[] = "abccccdd";
    int ans = longestPalindrome(a);
    printf("%d", ans);
    return 0;
}