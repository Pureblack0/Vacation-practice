/*字符串 S 由小写字母组成。我们要把这个字符串划分为尽可能多的片段，同一个字母只会出现在其中的一个片段。返回一个表示每个字符串片段的长度的列表。
示例 1：
输入：S = "ababcbacadefegdehijhklij"
输出：[9,7,8]
解释：
划分结果为 "ababcbaca", "defegde", "hijhklij"。
每个字母最多出现在一个片段中。
像 "ababcbacadefegde", "hijhklij" 的划分是错误的，因为划分的片段数较少。*/
int* partitionLabels(char * S, int* returnSize){
    if (S == NULL) {
        return 0;
    }
    int start = 0;
    int end = 0;
    int lenth = strlen(S);
    int *lenthAll = (int *)malloc(100*sizeof(int));
    int m = 0;
    for (int starts = start; starts < lenth; starts++) {
        for (int i = starts + 1; i < lenth; i++) {
            if (S[i] == S[starts] && (i > end)) {
                end  = i;
            }
        }
        if (starts >= end) {
            lenthAll[m++] = end - start + 1;
            start = end + 1;
            end = start;
        }
    }
    *returnSize = m;
    return lenthAll;
}

