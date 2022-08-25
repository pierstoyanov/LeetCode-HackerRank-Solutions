using System;
using System.Collections.Generic;
using System.IO;
class Solution {
    static void Main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution */
        for(int i=1;i<=100;i++)
        {
                               
         string res=(i%3==0&&i%5==0)?"FizzBuzz":(i%5==0)?"Buzz":
                    (i%3==0)?"Fizz":i.ToString();
            Console.WriteLine(res);
        }
        
    }
}