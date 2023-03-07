using System.Runtime.CompilerServices;

namespace LeetCode
{
    public class _98_ValidateBST
    {
        public class TreeNode
        {
            public int val;
            public TreeNode left;
            public TreeNode right;
            public TreeNode(int val = 0, TreeNode left = null, TreeNode right = null)
            {
                this.val = val;
                this.left = left;
                this.right = right;
            }
        }
        public static bool IsValidBST(TreeNode root)
        {
            if (root == null) { return true; }

            int MaxValue(TreeNode node) 
            {
                if (node == null) { return int.MinValue; }

                int maxLeft = MaxValue(node.left);
                int maxRight = MaxValue(node.right);
                return new int[] { node.val, maxLeft, maxRight }.Max() ;
            }

            int MinValue(TreeNode node)
            {
                if (node == null) { return int.MaxValue; }

                int minLeft = MinValue(node.left);
                int minRight = MinValue(node.right);
                return new int[] { node.val, minLeft, minRight }.Min();
            }

            var queue = new Queue<TreeNode>();
            queue.Enqueue(root);

            while (queue.Count > 0)
            {
                var currentNode = queue.Dequeue();

                if (currentNode.left != null)
                {

                    if (currentNode.val < MaxValue(currentNode.left))
                    { return false; }

                    queue.Enqueue(currentNode.left);

                }

                if (currentNode.right != null)
                {
                    if (currentNode.val > MinValue(currentNode.right))
                    { return false; }

                    queue.Enqueue(currentNode.right);
                }
            }

            return true;
        }
    }
}