/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int val=0, ListNode next=null) {
 *         this.val = val;
 *         this.next = next;
 *     }
 * }
 */
public class Solution {
   public ListNode RemoveNthFromEnd(ListNode head, int n) {
        var currentNode = head;
        var nBehind = head;
        int steps = 0;
        
        //move currentNode n steps forward
        for (int i = 0; i < n; i++)
        {
            if (currentNode.next == null)
            {
                if (i == n - 1)
                {
                    head = head.next;
                    return head;
                }
            }

            currentNode = currentNode.next;
        }

        //move both pointers to end of list
        while (currentNode.next != null)
        {
            currentNode = currentNode.next;
            nBehind = nBehind.next;
        }

        nBehind.next = nBehind.next.next;
        return head;
    }
}