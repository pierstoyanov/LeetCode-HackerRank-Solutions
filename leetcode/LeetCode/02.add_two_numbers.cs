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
    public ListNode AddTwoNumbers(ListNode l1, ListNode l2) {
        ListNode result = new ListNode();
        //set two pointers for the lists
        var currentOne = l1;
        var currentTwo = l2;
        var currentNew = result;
        int carry = 0;

        while (currentOne !=null || currentTwo != null || carry != 0)
        {
            int a = currentOne != null ? currentOne.val : 0;
            int b = currentTwo != null ? currentTwo.val : 0;

            ListNode newNode = new ListNode((a + b + carry) % 10);

            if (a + b + carry >= 10)
                carry = (a + b + carry) / 10;
            else
                carry = 0;

            currentNew.next = newNode;
            currentNew = currentNew.next;

            currentOne = currentOne != null ? currentOne.next : null;
            currentTwo = currentTwo != null ? currentTwo.next : null;
        }

        return result.next;
    }
}