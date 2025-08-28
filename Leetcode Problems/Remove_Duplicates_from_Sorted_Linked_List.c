struct ListNode* deleteDuplicates(struct ListNode* head) {
    if(head == NULL) return head;
    struct ListNode* ptr = head;
    if(ptr->next == NULL){
        return head;
    }
    struct ListNode* ptr2 = ptr->next;
    while(ptr2 != NULL){
        if(ptr2->val == ptr->val) ptr2 = ptr2->next;
        else{
            ptr->next = ptr2;
            ptr = ptr->next;
            ptr2 = ptr2->next;
        }
    }
    ptr->next = ptr2;
    return head;
}