using System.ComponentModel.Design;
using System.Runtime.CompilerServices;

namespace LeetCode
{
    public class _112_PathSum
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
        public static bool HasPathSum(TreeNode root, int targetSum)
        {
            if (root == null) { return false; }

            static bool DFS(TreeNode node, int targetSum, int currentSum)
            {
                if (node == null) { return false; }

                currentSum += node.val;

                // check is leaf node
                if (node.left == null && node.right == null)
                {
                    if (currentSum == targetSum) { return true; }
                    else { return false; }
                }

                return DFS(node.left, targetSum, currentSum) ||
                    DFS(node.right, targetSum, currentSum);
            }


            bool result = DFS(root, targetSum, 0);

            return result;
        }

    }
}