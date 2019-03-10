# BFS
class Solution:
    def cloneGraph(self, node: 'Node') -> 'Node':
        if not node :
            return
        copynode = Node(node.val, [])
        dic = {node: copynode}
        queue = collections.deque([node])
        
        while queue :
            temp = queue.popleft();
            for neighbor in temp.neighbors :
                if neighbor not in dic :
                    copynode = Node(neighbor.val, [])
                    dic[neighbor] = copynode
                    dic[temp].neighbors.append(copynode)
                    queue.append(neighbor)
                else :
                    dic[temp].neighbors.append(dic[neighbor])
        
        return dic[node]

# DFS
class Solution:
    def cloneGraph(self, node: 'Node') -> 'Node':
        dic = {}
        def DFS(node) :
            if not node :
                return 
            if node in dic :
                return dic[node]
            dic[node] = Node(node.val, [])
            
            for neighbor in node.neighbors :
                dic[node].neighbors.append(DFS(neighbor))
            
            return dic[node]
        
        return DFS(node)