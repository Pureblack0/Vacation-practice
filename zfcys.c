/*字符串压缩。利用字符重复出现的次数，编写一种方法，实现基本的字符串压缩功能。比如，
字符串aabcccccaaa会变为a2b1c5a3。若“压缩”后的字符串没有变短，则返回原先的字符串。
你可以假设字符串中只包含大小写英文字母（a至z）。
示例1:
 输入："aabcccccaaa"
 输出："a2b1c5a3"
示例2:
 输入："abbccd"
 输出："abbccd"
 解释："abbccd"压缩后为"a1b2c2d1"，比原字符串长度更长。
来源：力扣（LeetCode）*/
char* compressString(char* S){
    int size = strlen(S);
    if (size <= 2) return S;
    char* str = (char*)malloc(sizeof(char) * (2 * size));
    str[0] = S[0];
    int count = 1, index = 1;
    for (int i = 1; i < size + 1; i++) {
        if (S[i] == S[i - 1]) {
            count++;
        }
        else {
            int num = (int)log10(count) + index;
            index = num;
            while (count) {
                str[num--] = count % 10 +'0';
                count /= 10;
            }
            str[++index] = S[i];
            count = 1;
            ++index;
        }
    }
    if (index >= size + 1) return S;
    return str;
}
