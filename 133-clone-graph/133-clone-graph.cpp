/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    unordered_map<Node*, Node*>cpy;
    Node* deepCopy(Node* node) {
        if(cpy.find(node)!= cpy.end())
            return cpy[node];
        if(node == NULL)
            return NULL;
        Node* tempnode = new Node(node->val);
        cpy[node]=tempnode;
        for(Node* idx : node->neighbors){
            tempnode->neighbors.push_back(deepCopy(idx));
        }
        return tempnode;
    }
    Node* cloneGraph(Node* node) {
        return deepCopy(node);
    }
};