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

//time: O(V+E)
//space: O(V)
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;
        unordered_map<Node*, Node*> umap;
        Node* copy = new Node(node -> val);
        umap[node] = copy;
        queue<Node*> q;
        q.push(node);
        while(!q.empty()) {
            Node* curr = q.front();
            q.pop();
            for(Node* n : (curr -> neighbors)) {
                if(umap.find(n) == umap.end()) {
                    Node* newNode = new Node(n -> val);
                    umap[n] = newNode;
                    q.push(n);
                }
                (umap[curr] -> neighbors).push_back(umap[n]);
            }
        }
        return copy;
    }
};