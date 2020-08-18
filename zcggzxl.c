/*给定两个字符串 text1 和 text2，返回这两个字符串的最长公共子序列的长度。
一个字符串的 子序列 是指这样一个新的字符串：它是由原字符串在不改变字符的相对顺序的情况下删除某些字符（也可以不删除任何字符）后组成的新字符串。
例如，"ace" 是 "abcde" 的子序列，但 "aec" 不是 "abcde" 的子序列。两个字符串的「公共子序列」是这两个字符串所共同拥有的子序列。
若这两个字符串没有公共子序列，则返回 0。
示例 1:
输入：text1 = "abcde", text2 = "ace" 
输出：3  
解释：最长公共子序列是 "ace"，它的长度为 3。
示例 2:
输入：text1 = "abc", text2 = "abc"
输出：3
解释：最长公共子序列是 "abc"，它的长度为 3。
示例 3:
输入：text1 = "abc", text2 = "def"
输出：0
解释：两个字符串没有公共子序列，返回 0。
来源：力扣（LeetCode）*/
/*解题思路
定义int dp[1001][1001]数组用于存放最长公共子序列的长度的所有值，并元素都初始化为0；
遍历dp数组从1开始，检查判断text1[i-1]与text2[j-1]的值，判断当前字符的最长公共子序列；
遍历完成dp[strlen(text1)][strlen(text2)]的值即是最长公共子序列长度。*/
#define max(A,B) ((A) > (B) ? (A) : (B))
int longestCommonSubsequence(char * text1, char * text2){
    if(text1 == NULL || strlen(text1) == 0) return 0;
    if(text2 == NULL || strlen(text2) == 0) return 0;
    int i,j,lcs;
    int dp[1001][1001] = {0};

    for(i = 1; i <= strlen(text1); i++) {
        for(j = 1; j <= strlen(text2); j++) {
            if(text1[i - 1] == text2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }

    lcs = dp[strlen(text1)][strlen(text2)];
    return lcs;
}

