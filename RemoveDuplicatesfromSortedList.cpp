class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next;
        set<int> st;
        
        while(curr){
            next = curr ->next;
            if(st.find(curr->val) != st.end()){
                prev->next = next;
                curr = NULL;
                curr = next;
                
            }else{
                st.insert(curr->val);
                prev = curr;
                curr = next;
            }
            
            
            
        }
        
        return head;
        
    }
};

// Here we are using set tu check whether the element is visited or not 

// another way could be 

ListNode* deleteDuplicates(ListNode* head) {
        ListNode* cur = head;
        while(cur) {
        	while(cur->next && cur->val == cur->next->val) {
        		cur->next = cur->next->next;
        	}
        	cur = cur->next;
        }
        return head;
    }
