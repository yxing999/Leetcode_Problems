class Solution:
    def addOperators(self, num: str, target: int) -> List[str]:
        res = []
        n = len(num)
        
        def DFS(cur_str, pre_num, cur_val, pos) :
            if pos == n :
                if cur_val == target :
                    res.append(cur_str)
                return
            
            for i in range(pos + 1, n + 1) :
                if num[pos] == '0' and i > pos + 1 :
                    return
                    
                add_str = num[pos:i]
                add_num = int(add_str)
                
                if pos == 0 :
                    DFS(add_str, add_num, add_num, i)
                else :
                    DFS(cur_str + "+" + add_str, add_num, cur_val + add_num, i)
                    DFS(cur_str + "-" + add_str, -add_num, cur_val - add_num, i)
                    DFS(cur_str + "*" + add_str, pre_num * add_num, cur_val - pre_num + pre_num * add_num, i)
                
        DFS("", 0, 0, 0)
        
        return res