class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> data;
        vector<int> ans;
        stack<int> temp;
        while(head){
            data.push_back(head->val);
            head=head->next;
        }
        
        int size = data.size();
        for(int i = size-1 ; i >= 0 ;i--){
            if(temp.empty()){
                ans.push_back(0);
                temp.push(data[i]);
            }
            else{
                while(!temp.empty() ){
                    int top =   temp.top();
                    if(top > data[i]){
                        ans.push_back(top);
                        temp.push(data[i]);
                        break;
                    }else{
                        temp.pop();
                    }
                }
                
                if(temp.empty()){
                    ans.push_back(0);
                    temp.push(data[i]);
                }
            }
            
            
        }
        
        reverse(ans.begin() , ans.end());
        
        return ans;
    }
};


// Or Same Approach

vector<int> nextLargerNodes(ListNode* h) {
  vector<int> res, stack;
  for (auto p = h; p != nullptr; p = p->next) res.push_back(p->val);
  for (int i = res.size() - 1; i >= 0; --i) {
    auto val = res[i];
    while (!stack.empty() && stack.back() <= res[i]) stack.pop_back();
    res[i] = stack.empty() ? 0 : stack.back();
    stack.push_back(val);
  }
  return res;
}
