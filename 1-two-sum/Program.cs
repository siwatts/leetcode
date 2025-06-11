using System.IO;

public class Solution
{
    public static int[] TwoSum(int[] nums, int target)
    {
        // Indices of the 2 elements from num that sum to target
        // Assume exactly 1 sol'n per problem

        Console.WriteLine("Nums length: {0}", nums.Length);
        Console.WriteLine("Target: {0}", target);
        Console.WriteLine("Running for loop from 0 to {0}", nums.Length);
        for (int i = 0; i < nums.Length; i++)
        {
            Console.WriteLine("For loop i = {0}", i);
            for (int j = i + 1; j < nums.Length; j++)
            {
                Console.WriteLine("For loop j = {0}", j);
                if (nums[i] + nums[j] == target)
                {
                    Console.WriteLine("Found target {0} at [{1}, {2}]", target, i, j);
                    int[] res = [i, j];
                    return res;
                }
                else
                {
                    Console.WriteLine("Target not found {0} at [{1}, {2}]", target, i, j);
                }
            }
        }
        return null;
    }
}
public class Program
{
    public static int Main(string[] args)
    {
        int[] nums = [3,2,4];
        int target = 6;

        var result = Solution.TwoSum(nums, target);
        Console.WriteLine("Result [{0}, {1}]", result[0], result[1]);

        return 0;
    }
}
