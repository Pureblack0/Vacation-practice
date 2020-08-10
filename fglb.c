/*给定一个头结点为 root 的链表, 编写一个函数以将链表分隔为 k 个连续的部分。
每部分的长度应该尽可能的相等: 任意两部分的长度差距不能超过 1，也就是说可能有些部分为 null。
这k个部分应该按照在链表中出现的顺序进行输出，并且排在前面的部分的长度应该大于或等于后面的长度。
返回一个符合上述规则的链表的列表。
举例： 1->2->3->4, k = 5 // 5 结果 [ [1], [2], [3], [4], null ]
来源：力扣（LeetCode）*/
struct ListNode** splitListToParts(struct ListNode* root, int k, int* returnSize){
    struct ListNode* cur=root;
    int count=0;
    while(cur)
    {
        count++;
        cur=cur->next;
    }
    cur=root;

    struct ListNode **arr=(struct ListNode**)calloc(k,sizeof(struct ListNode*));
    int size=count/k;
    int len=count%k;
    for(int i=0;i<k;i++)
    {
        arr[i]=cur;
        if(i<len)
        {
            int j=0;
            while(j<size)
            {
                j++;
                cur=cur->next;
            }
            struct ListNode *pre=cur;
            cur=cur->next;
            pre->next=NULL;
        }
        else
        {
            if(size)
            {
                int j=0;
                while(j<size-1)
                {
                    j++;
                    cur=cur->next;
                }
                struct ListNode *pre=cur;
                cur=cur->next;
                pre->next=NULL;
            }
            else
                arr[i]=NULL;
        }
    }
    *returnSize=k;
    return arr;
}
