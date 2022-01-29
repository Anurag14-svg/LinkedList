class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2)    {
        ListNode* p = list1 ;
        ListNode* s = NULL;
        for(int i = 0 ; i < b ; i++){
            if(i == a-1) s = p;
            p = p->next;
        }
        s->next= list2;
        while(list2->next) list2 = list2->next;
        list2->next = p->next;
        
        return list1;
       
    }
};
