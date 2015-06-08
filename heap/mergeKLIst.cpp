#include "basic.h"
static bool mycomp(ListNode *x, ListNode *y){
    return x->val < y->val;
}

ListNode *mergeKLists(vector<ListNode *> &lists) {
    ListNode *begin = new ListNode(0);
    ListNode *current = begin;
    priority_queue<ListNode*,vector<ListNode>, mycomp> q;
    for(auto each:lists){
        q.push(each);
    }
    while(!q.empty()){
        ListNode *tmp = q.top();//new ListNode(q.top()->val);
        q.pop();
        current->next = tmp;
        current = current->next;
        if(tmp->next){
            q.push(tmp->next);
        }
    }
    return begin->next;
}
int main(){
    int x[] = {1,3,5};
    int y[] = {2,4,6};
    ListNode *x1 = getList(x[],sizeof(x)/sizeof(x[0]));
    ListNode *x2 = getList(y[],sizeof(y)/sizeof(y[0]));
    vector<ListNode*> lists;
    lists.push_back(x1);
    lists.push_back(x2);
    ListNode* result = mergeKLists(lists);
    print(result);
}