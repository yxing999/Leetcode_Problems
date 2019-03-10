//Solution 1
class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> mapping;
        queue<Node*> q;
        q.push(node);
        
        while(!q.empty()) {
            Node *temp = q.front(); q.pop();
            mapping[temp] = new Node(temp->val, {});
            for(auto neighbor: temp->neighbors){
                if(!mapping.count(neighbor)) q.push(neighbor);
            }
        }
        
        for (auto ele: mapping) {
            for(auto neighbor: ele.first->neighbors) {
                ele.second->neighbors.push_back(mapping[neighbor]);
            }
        }
        return mapping[node];
    }
};

//Solution 2
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return NULL;
        if (mapping.count(node)) return mapping[node];
        
        mapping[node] = new Node(node->val, {});
        for(auto neighbor: node->neighbors) {
            mapping[node]->neighbors.push_back(cloneGraph(neighbor));
        }
        return mapping[node];
    }
    
    unordered_map<Node*, Node*> mapping;
};