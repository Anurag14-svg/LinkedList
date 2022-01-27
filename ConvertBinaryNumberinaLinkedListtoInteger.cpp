class Solution {
public:
    int getDecimalValue(ListNode* head) {
        ListNode* temp = head ;
        string s = "";
        int ans = 0 ;
        int j = 0;
        while(temp != NULL){
            s+= to_string(temp->val);
            temp = temp->next;
        }
        
        for(int i = s.length() - 1 ; i >= 0 ;i--){
            ans += (s[i] -'0') * pow(2,j);
            j++;
        }
        
        return ans;
    }
};


// The above solution will take o(N) time
// And O(N) space complexity as we are storing the whole linked list in the string 

//We can definitely reduce the space complexity by doing this solution in one paas 

// for ex- 

//whenever it is asked to convert a binary into decimal there is a small trick you should know

//Supoose the binary number is 1011
// int i = 0 ;


//Start iteratinmg from the start 
 // 2 * i + 1 = 1; whatever we will recieve it will become our new i;
//  2* 1 + 0 = 2;
//  2 * 2 + 1 = 5;
//  2* 5 + 1 = 11;

// 11 is the answer;

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int res=0;
        while(head!=NULL){
            res=res*2+head->val;
            head=head->next;
        }
        return res;
    }
};



