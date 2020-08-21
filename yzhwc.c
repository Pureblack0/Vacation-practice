/*给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
说明：本题中，我们将空字符串定义为有效的回文串。
示例 1:
输入: "A man, a plan, a canal: Panama"
输出: true
示例 2:
输入: "race a car"
输出: false*/
bool isPalindrome(char *str)
{
    int i, n;

    if (str == NULL) {
        return 0;
    } else if (strlen(str) == 0) {
        return 1;
    }

    n = strlen(str) - 1;
    for (i = 0; i <= n;) {
        // 过滤数字和字母
        if (!isalnum(str[i])) {
            i++;
            continue;
        }
        if (!isalnum(str[n])) {
            n--;
            continue;
        }
        // 判断首尾是否相同，忽略大小写
        if (tolower(str[i]) != tolower(str[n])) {
            return false;  // 不相同，返回不是回文串
        }
        i++;
        n--;
    }

    return true;
}
