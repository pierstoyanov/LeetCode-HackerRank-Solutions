
namespace LeetCode
{
    public class _20_ValidParenthesis
    {
        public bool IsValid(string s)
        {
            Stack<char> bracketStack = new Stack<char>();
            char[] opening = { '[', '{', '(' };
            char[] closing = { ']', '}', ')' };
            bool result = false;

            foreach (char c in s)
            {
                if (closing.Contains(c))
                {
                    var matchingOpeningBracket = opening[Array.IndexOf(closing, c)];

                    if (bracketStack.Count != 0 && matchingOpeningBracket == bracketStack.Peek())
                    {
                        result = true;
                        bracketStack.Pop();
                        continue;
                    }
                    else
                    {
                        result = false;
                        break;
                    }
                }

                if (opening.Contains(c))
                {
                    bracketStack.Push(c);
                    result = false;
                }
            }

            if (bracketStack.Count > 0)
                return false;

            return result;
        }
    }
}

