/*在字符串 s 中找出第一个只出现一次的字符。如果没有，返回一个单空格。 s 只包含小写字母。
示例:
s = "abaccdeff"
返回 "b"
s = "" 
返回 " "
限制：
0 <= s 的长度 <= 50000
来源：力扣（LeetCode）*/
#define NUM_MAX 256

int g_hash[NUM_MAX];

char firstUniqChar(char *s)
{
    int i;
    int str_len = strlen(s);

    memset(g_hash, 0, sizeof(int) * NUM_MAX);
    for (i = 0; i < str_len; i++) {
        g_hash[s[i] - 'a']++;
    }

    for (i = 0; i < str_len; i++) {
        if (g_hash[s[i] - 'a'] == 1) {
            return s[i];
        }
    }

    return "";
}

