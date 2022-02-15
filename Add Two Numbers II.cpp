class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> stack1;
        stack<int> stack2;
        
        while(l1){
            stack1.push(l1->val);
            l1 = l1->next;
        }
        
        while(l2){
            stack2.push(l2->val);
            l2 = l2->next;
        }
        
        ListNode* List = NULL;
        int sum;
        while(!stack1.empty() || !stack2.empty() ){
            if(!stack1.empty()) {
                sum += stack1.top();
                stack1.pop();
            }
                
            if(!stack2.empty()) {
                sum += stack2.top();
                stack2.pop();
            }
            
            
            ListNode* head = new ListNode(sum % 10);
            head->next = List;
            List = head;
            
            sum = sum /10;
         }
        
        if(sum != 0){
            ListNode* head = new ListNode(sum);
            head->next = List;
            List = head;
        }
        
        return  List;
    }
};

// or another  modified method could be 


int sum = 0;
        ListNode list = new ListNode(0);
        while (!s1.empty() || !s2.empty()) {
            if (!s1.empty()) sum += s1.pop();
            if (!s2.empty()) sum += s2.pop();
            list.val = sum % 10;
            ListNode head = new ListNode(sum / 10);
            head.next = list;
            list = head;
            sum /= 10;
        }
        
        return list.val == 0 ? list.next : list;

// //The second method is just the a upgrade version for the edge case that if our addition  in 10 and no previous element is present the we will not end up just getting 0 but 1 , 0
