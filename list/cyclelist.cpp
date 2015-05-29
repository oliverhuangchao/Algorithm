ListNode* findMerge(ListNode* fast,ListNode* slow){
    int l1=0;
    int l2=0;
    ListNode* a = fast;
    ListNode* b = slow;
    while(a){a=a->next;l1++;}
    while(b){b=b->next;l2++;}
    if(l1>l2)
        for(int i=0;i<l1-l2;i++)    fast = fast->next;
    else
        for(int i=0;i<l2-l1;i++)    slow = slow->next;
    while(fast!=slow){
        fast = fast->next;
        slow = slow->next;
    }
    return fast;
}
//firstly find the break point of these two pointers
//then call findMerge as a "Y" linklist
ListNode *detectCycle(ListNode *head) {
    if(!head) return NULL;
    ListNode* fast = head->next;
    ListNode* slow = head;
    while(fast != slow ){
        if( !fast  || !fast->next ) return NULL;
        //if(!slow) return NULL;
        fast = fast->next->next;
        slow = slow->next;
    }
    fast = fast->next;
    slow->next = NULL;
    slow = head;
    return findMerge(fast,slow);
}