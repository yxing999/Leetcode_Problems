'''
Follow the stack rule, try to add from pushed and pop from popped if you can.

Time: O(n),
Space: O(1).
'''

class Solution:
    def validateStackSequences(self, pushed: List[int], popped: List[int]) -> bool:
        push, pop = 0, 0
        while push < len(pushed) :
            if pushed[push] != popped[pop] :
                push += 1
            else :
                pop += 1
                pushed.remove(pushed[push])
                if push > 0 :
                    push -= 1
        
        return len(pushed) == 0