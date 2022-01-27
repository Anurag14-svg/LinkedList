class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL; 
        ListNode* curr = head;
        ListNode* next;
        
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            
            
        }
        
        return prev;
        
        
    }
    
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
    
    
    bool isPalindrome(ListNode* head) {
        ListNode* curr = head;
        ListNode* mid = middleNode(head);
        ListNode* last = reverseList(mid);
        
        while(last!=NULL){
            if(curr->val != last->val){
                return false;
            }
            curr = curr->next;
            last = last->next;
        }
        
        return true;
    }
};

// or recursively 

class Solution {
public:
    ListNode* temp;
    bool isPalindrome(ListNode* head) {
        temp = head;
        return check(head);
    }
    
    bool check(ListNode* p) {
        if (NULL == p) return true;
        bool isPal = check(p->next) & (temp->val == p->val);
        temp = temp->next;
        return isPal;
    }
};
