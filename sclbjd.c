/*给定单向链表的头指针和一个要删除的节点的值，定义一个函数删除该节点。
返回删除后的链表的头节点。
示例 1:
输入: head = [4,5,1,9], val = 5
输出: [4,1,9]
解释: 给定你链表中值为 5 的第二个节点，那么在调用了你的函数之后，该链表应变为 4 -> 1 -> 9.
来源：力扣（LeetCode）*/
struct ListNode* deleteNode(struct ListNode* head, int val){
    if(head==NULL) return head;
    if(head->next==NULL){
        if(head->val==val) return NULL;
        else return head;
    }
    struct ListNode *pre=head,*q=pre->next;
    if(head->val==val) return head->next;
    while(q){
        if(q->val==val){
            pre->next=q->next;
            free(q);
            return head;
        }else{
            pre->next=q;
            pre=q;
            q=q->next;
        }
    }
    return head;
}
