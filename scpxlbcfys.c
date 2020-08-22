/*给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。
示例 1:
输入: 1->1->2
输出: 1->2
示例 2:
输入: 1->1->2->3->3
输出: 1->2->3
来源：力扣（LeetCode）*/
struct ListNode* deleteDuplicates(struct ListNode* head){
    if (head == NULL || head->next == NULL) {
        return head;
    }

    // 删除头节点后面挂接的链表中的重复元素
    head->next = deleteDuplicates(head->next);
    
    //  头节点与后面挂接的链表中的节点值相同，则头节点也删除，否则不删除
    return head->val == head->next->val ? head->next : head;
}
