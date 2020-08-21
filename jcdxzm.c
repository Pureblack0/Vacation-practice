/*给定一个单词，你需要判断单词的大写使用是否正确。
我们定义，在以下情况时，单词的大写用法是正确的：
全部字母都是大写，比如"USA"。
单词中所有字母都不是大写，比如"leetcode"。
如果单词不只含有一个字母，只有首字母大写， 比如 "Google"。
否则，我们定义这个单词没有正确使用大写字母。
示例 1:
输入: "USA"
输出: True
示例 2:
输入: "FlaG"
输出: False
来源：力扣（LeetCode）*/
bool detectCapitalUse(char * word){
    
    int len = strlen(word);
    int cnt = 0;
    for(int i = 0;i<len;i++)
    {
        if((word[i] >='A' )&&(word[i] <='Z'))
        cnt++;     
    }
    //对应情况1和情况3
    if((cnt == len)||(cnt == 0))
        return true;
    //对应情况2
    else if(((word[0]>='A')&&(word[0]<='Z')&&(cnt==1)))
         return true;
    else 
    return false;

}

