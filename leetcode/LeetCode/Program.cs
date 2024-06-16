using System.Runtime.CompilerServices;

using static LeetCode._112_PathSum;

namespace LeetCode
{
    internal class Program
    {
        static void Main(string[] args)
        {
            var t = new TreeNode(5, 
                        new TreeNode(4, 
                            new TreeNode(11,
                                new TreeNode(7),
                                new TreeNode(2)), 
                        new TreeNode(8, 
                            new TreeNode(13),
                            new TreeNode(4, null,
                                new TreeNode(1)))));
            var targetSum = 22;
            Console.WriteLine(HasPathSum(t, targetSum));
        }

        private static void ValidParenthesis()
        {
            var s = new _20_ValidParenthesis();
            //Console.WriteLine($"True: {s.IsValid("()")}\n");
            //Console.WriteLine($"True: {s.IsValid("()[]{}")} \n");
            //Console.WriteLine($"False: {s.IsValid("(]")} \n");
            //Console.WriteLine($"False: {s.IsValid("([]){")} \n");
            Console.WriteLine($"False: {s.IsValid("([]")} \n");

        }

        private static void NetworkDelayTime()
        {
            var s = new _743_NetworkDelayTimeSolution();

            var times = new int[][] {
                new int[] { 2, 1, 1 },
                new int[] { 2, 3, 1 },
                new int[] { 3, 4, 1 } };
            var n = 4;
            var k = 2;

            Console.WriteLine(s.NetworkDelayTime(
                times, n, k
                ));
        }
    }
}