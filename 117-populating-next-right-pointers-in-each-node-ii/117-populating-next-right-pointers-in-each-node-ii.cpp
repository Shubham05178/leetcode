class Solution {
public:
    Node* connect(Node* root) {
        Node * temp,*prev,*next ,*pprev,*curr = root;
        while(curr!= NULL){
            temp = curr;
            prev = NULL;
            next = NULL;
            pprev = NULL;
            while(temp){
                //finding first
                while(temp && prev ==NULL){
                    if(temp->left){
                        prev = temp->left;
                        break;
                    }
                    if(temp->right){
                        prev = temp->right;
                        break;
                    }
                    temp= temp->next;
                }
                //finding second
                next = NULL;
                while(temp){
                    if(temp->left && prev!= temp->left && pprev != temp->left){
                        next = temp->left;
                        break;
                    }
                    if(temp->right && prev!= temp->right && pprev != temp->right){
                        next = temp->right;
                        break;
                    }
                    temp= temp->next;
                }
                if(next && next!=curr) prev->next = next;
                if(next)
                pprev = prev;
                prev = next;
                if(next ==NULL || next == curr ) break;
            }
            while(curr){
                if(curr->left){
                curr = curr->left;
                    break;
                }
                if(curr->right){
                    curr=curr->right;
                    break;
                }
                curr= curr->next;
                
            }
        }
        return root;
    }
};