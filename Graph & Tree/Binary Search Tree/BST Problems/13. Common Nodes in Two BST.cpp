// Link: https://www.geeksforgeeks.org/problems/print-common-nodes-in-bst/1

class Solution {
  public:
    vector<int> findCommon(Node* r1, Node* r2) {
        vector<int>ans;
        stack<Node*>s1, s2;
        // all the left nodes of r1 push into stack s1
        while(r1){
            s1.push(r1);
            r1 = r1->left;
        }
        // all the left nodes of r2 push into stack s2
        while(r2){
            s2.push(r2);
            r2 = r2->left;
        }
        
        while(!s1.empty() and !s2.empty()){
            // total 3 cases here
            // top eles are equal
            if(s1.top()->data==s2.top()->data){
                ans.push_back(s1.top()->data);
                // before pop, go to the right side of that curr node for taking all left of it
                r1 = s1.top()->right;
                s1.pop();
                // same for r2
                r2 = s2.top()->right;
                s2.pop();
                // Now, all left of r1 & r2 will store in s1 & s2, this will happen for all cases thats why we write it later
            }
            // s1 > s2
            else if(s1.top()->data > s2.top()->data){
                // remove the smaller
                // before pop go to right side of that node, same process
                r2 = s2.top()->right;
                s2.pop();
            } else {   // s1 < s2
                r1 = s1.top()->right;
                s1.pop();
            }
            
            // Now process that right side's all left nodes
            while(r1){
                s1.push(r1);
                r1 = r1->left;
            }
            while(r2){
                s2.push(r2);
                r2 = r2->left;
            }
        }
        return ans;
    }
};
