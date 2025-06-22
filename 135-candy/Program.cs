
public class Child
{
    public Child? PrevChild;
    public Child? NextChild;
    public int Rating;
    private int candies = -1;
    public Child(int rating, Child? prevChild = null, Child? nextChild = null)
    {
        this.Rating = rating;
        this.PrevChild = prevChild;
        this.NextChild = nextChild;
    }
    public int Candies
    {
        get
        {
            if (candies != -1)
            {
                return candies;
            }
            else
            {
                // Calculate it
                candies = 1;
                if (PrevChild != null)
                {
                    if (PrevChild.Rating < Rating)
                    {
                        // Need at least one more than them, bidirectional
                        candies = Math.Max((int)candies, PrevChild.Candies + 1);
                    }
                }
                if (NextChild != null)
                {
                    if (NextChild.Rating < Rating)
                    {
                        // Need at least one more than them, bidirectional
                        candies = Math.Max((int)candies, NextChild.Candies + 1);
                    }
                }
                return candies;
            }
        }
    }
}

public class Solution
{
    public int Candy(int[] ratings)
    {
        List<Child> children = ratings.Select(r => new Child(r)).ToList<Child>();
        int n = children.Count;
        if (n == 1)
        {
            // Special case, nothing to link if there's only 1 child
            return 1;
        }
        // Go through and link them
        // All but first and last are bidirectional
        children[0].NextChild = children[1];
        children[n-1].PrevChild = children[n-2];
        for (int i = 1; i < n - 1; i++)
        {
            children[i].NextChild = children[i+1];
            children[i].PrevChild = children[i-1];
        }

        return children.Sum(c => c.Candies);
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

