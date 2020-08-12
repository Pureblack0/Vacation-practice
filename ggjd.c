/*输入两个链表，找出它们的第一个公共节点。
示例 ：
输入：intersectVal = 8, listA = [4,1,8,4,5], listB = [5,0,1,8,4,5], skipA = 2, skipB = 3
输出：Reference of the node with value = 8
输入解释：相交节点的值为 8 （注意，如果两个列表相交则不能为 0）。从各自的表头开始算起，链表 A 为 [4,1,8,4,5]，链表 B 为 [5,0,1,8,4,5]。在 A 中，相交节点前有 2 个节点；在 B 中，相交节点前有 3 个节点。
注意：公共节点意思是指针地址相同，而不是指针指向的值相同，所以上述示例中第一个公共节点不是1而是8
来源：力扣（LeetCode）*/
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *p_1=headA,*p_2=headB;
    while(p_1!=0&&p_2!=0){
        p_1=p_1->next;
        p_2=p_2->next;
    }
    if(p_1==0){
        p_1=headA;
        headA=headB;
        headB=p_1;
        p_1=p_2;
    }
    while(p_1!=0){
        headA=headA->next;
        p_1=p_1->next;
    }
    while(headA!=0){
        if(headA==headB) return headA;
        headA=headA->next;
        headB=headB->next;
    }
    return 0;
}


