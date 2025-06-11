using System.IO;

public class Solution
{
    public int Candy(int[] ratings)
    {
        // n children in a line
        // each with rating at index
        // must have at least 1 candy each
        // higher rating = more candies than their immediate neighbours
        // find min. no. of candies req'd

        // Everyone must have at least 1 candy
        int[] candies = Enumerable.Repeat(1, ratings.Length).ToArray<int>();

        // Step through
        for (int i = 1; i < ratings.Length; i++)
        {
            // If next child has higher or lower than prev. then extra candy needed for one of them
            if (ratings[i] != ratings[i-1])
            {
                if (ratings[i] > ratings[i-1])
                {
                    // One more than previous kids
                    candies[i] = candies[i-1] + 1;
                }
                else
                {
                    // Previous kid needs 1 more than this kid *at least*
                    // He may have already had higher because we already dealt with him before
                    // so don't downgrade him!
                    candies[i-1] = Math.Max(candies[i] + 1, candies[i-1]);
                }
            }
        }

        return candies.Sum();
    }
}

public class Program
{
    public static int Main(string[] args)
    {
        Console.WriteLine("Candy");
        int[] ratings = [1,0,2];
        Solution soln = new Solution();
        int output = soln.Candy(ratings);
        Console.WriteLine("Output: {0}", output);

        return 0;
    }
}

