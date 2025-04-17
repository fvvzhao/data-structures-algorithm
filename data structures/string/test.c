#include <stdio.h>
#include <string.h>

int get_string_index(const char* str, const char* substr);

int main(void) {

    printf("%d\n", get_string_index("googoogle", "google"));

    return 0;
}

// 朴素模式匹配算法
int get_string_index(const char* str, const char* substr) {
    int str_len = strlen(str);
    int substr_len = strlen(substr);
    int count;

    if (str_len < substr_len) {
        puts("主串长度小于模式串");
        return -1;
    }

    for (int i = 0; i < str_len - substr_len + 1; i++) {
        for (int j = 0; j < substr_len; j++) {
            if (substr[j] != str[j + i]) {
                count = 0;
                break;
            }
            else {
                count++;
                if (count == substr_len) {
                    return i;
                }
            }
        }
    }
}
