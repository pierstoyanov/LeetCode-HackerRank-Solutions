using System.Runtime.CompilerServices;

namespace LeetCode
{
    public class _94_BinaryTreeInOrderIter
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

        public IList<int> InorderTraversal(TreeNode root)
        {
            if (root == null) { return new List<int>(); }

            var result = new List<int>();
            Stack<TreeNode> stack = new Stack<TreeNode>();

            var currentNode = root;

            while (currentNode != null || stack.Count > 0) 
            {
                // reach bottom left
                while (currentNode != null)
                {
                    stack.Push(currentNode);
                    currentNode = currentNode.left;
                }

                currentNode = stack.Pop();

                result.Add(currentNode.val);

                currentNode = currentNode.right;
            }

            return result;
        }
    }
}