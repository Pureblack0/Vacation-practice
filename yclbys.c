/*删除链表中等于给定值 val 的所有节点。
示例:
输入: 1->2->6->3->4->5->6, val = 6
输出: 1->2->3->4->5*/
struct ListNode* removeElements(struct ListNode* head, int val){ 
    if (head == NULL) {
        return NULL;
    }     

    //  删除 head 后面值为 val 的元素的链表
    struct ListNode* res = removeElements(head->next, val);
    //  head 节点是要删除的节点
    if (head->val == val) {
        return res;
    } else {
        head->next = res;
        return head;
    }
}
