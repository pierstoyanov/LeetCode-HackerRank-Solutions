# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
class Solution:
    def sum_l(one, two):
        new = []
        remainder = 0
        for i in range(len(one)):
            try:
                node = one[i] + two[i] + remainder
                
                if node >= 10:
                    remainder = node - 9
                    new.append(0)
                
                else:
                    new.append(node)

            except IndexError:
                if  remainder != 0:
                    new.append(remainder + one[i])
                else:
                    new.append(one[i])
        
        if  remainder != 0:
            new.append(remainder)
        return new
    
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        list_1 = ''.join(map(int, l1[::-1]))
        list_2 = ''.join(map(str, l2[::-1]))

        if len(list_1) > len(list_2):
            new_list = Solution.sum_l(list_1, list_2)
        else:
            new_list = Solution.sum_l(list_2, list_1)
        
        return new_list




a = Solution()
print(a.addTwoNumbers([2,9,3], [5,6,4]))
        