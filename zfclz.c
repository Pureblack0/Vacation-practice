/*字符串轮转。给定两个字符串s1和s2，请编写代码检查s2是否为s1旋转而成（比如，waterbottle是erbottlewat旋转后的字符串）。
示例1:

 输入：s1 = "waterbottle", s2 = "erbottlewat"
 输出：True
示例2:

 输入：s1 = "aa", s2 = "aba"
 输出：False

来源：力扣（LeetCode）*/
bool isFlipedString(char* s1, char* s2){
 int len1 = strlen(s1);
    int len2 = strlen(s2);

    
    if (len1 != len2)
        return false;
    else if (len1 == 0)
        return true;

    int len = len1;
    for (int i = 0; i < len; i++) {
        if (memcmp(s1, s2+len-1-i, i+1) == 0) {
            if (memcmp(s1+i+1, s2, len-1-i) == 0)
                return true;
        }
    }
    return false;

}
