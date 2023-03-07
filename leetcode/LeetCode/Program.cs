using System.Runtime.CompilerServices;

using static LeetCode._98_ValidateBST;

namespace LeetCode
{
    internal class Program
    {
        static void Main(string[] args)
        {
            var t = new TreeNode(2, new TreeNode(1), new TreeNode(3));
            Console.WriteLine(IsValidBST(t));
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