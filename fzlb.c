/*定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的头节点。
示例:
输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL*/
struct ListNode* reverseList(struct ListNode* head){
    if (head == NULL || head->next == NULL)
        return head;
    else
    {
        struct ListNode *newhead = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return newhead;
        
    }
}
 