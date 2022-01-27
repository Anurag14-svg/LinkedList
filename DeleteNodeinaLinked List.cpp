class Solution {
public:
    void deleteNode(ListNode* node) {
        while(node){
            if(node->next->next){
                swap(node->val , node->next->val);
            }
            else{
                swap(node->val, node->next->val);
                node->next = NULL;
            }
            
            node = node->next;
        }
    }
};

// This is the way if you think of removing a node by continuously swappinmg the values from the given node till the end of the list 

// But a better way could be


void deleteNode(ListNode* node) {
    *node = *node->next;
}

// Here what we are actually doing is we are changing the address 
// currently the pointer is pointing to the node to be deleted 
// Now the pointer will point to the next of node to be deleted 

// Better way 

void deleteNode(ListNode* node) {
    auto next = node->next;
    *node = *next;
    delete next;
}
