/*输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。
示例 1：
输入：head = [1,3,2]
输出：[2,3,1]*/
int* reversePrint(struct ListNode* head, int* returnSize){
    if(head==NULL){
        *returnSize=0;
        return NULL;
    }
    struct ListNode*p=head;
    int num=0;
    while(p!=NULL){
        p=p->next;
        num++;
    }
    int *res=(int *)malloc(sizeof(int)*num);
    for(int i=0;i<num;i++){
        res[num-1-i]=head->val;
        head=head->next;
    }
    *returnSize=num;
    return res;
}
