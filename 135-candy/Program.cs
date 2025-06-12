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
        int count = ratings.Length;
        //int[] candies = Enumerable.Repeat(1, ratings.Length).ToArray<int>();

        // Step through
        // Find longest unbroken chains of increases and decreases, as the candies will stack
        int increaseCount = 0;
        int decreaseCount = 0;
        for (int i = 1; i < ratings.Length; i++)
        {
            // If next child has higher than prev. then extra candy needed for one of them
            if (ratings[i] > ratings[i - 1])
            {
                increaseCount++;
                // Account for candies in the increase chain up to now
                // 1 increase = 1, 3 consecutive increases = 3 + 2 + 1 and so on
                count += increaseCount;
            }
            else if (increaseCount != 0)
            {
                // Reset
                increaseCount = 0;
            }

            // If next child has lower than prev. then extra candy needed for one of them
            if (ratings[i] < ratings[i - 1])
            {
                decreaseCount++;
                // Account for candies in the decrease chain up to now
                // 1 decrease = 1, 3 consecutive decreases = 3 + 2 + 1 and so on
                count += decreaseCount;
            }
            else if (decreaseCount != 0)
            {
                // Reset
                decreaseCount = 0;
            }
        }

        return count;
    }
}

public class Program
{
    public static int Main(string[] args)
    {
        Console.WriteLine("Candy");
        int[] ratings = [1, 3, 2, 2, 1];
        int expAnswer = 7; // -1 to ignore

        Solution soln = new Solution();
        int output = soln.Candy(ratings);
        Console.WriteLine("Output: {0}", output);
        if (expAnswer != -1 && output != expAnswer)
        {
            Console.WriteLine("Incorrect answer, the expected answer is {0}", expAnswer);
        }

        return 0;
    }
}

