/*
Given a list of folders folder, return the folders after removing all
sub-folders in those folders. You may return the answer in any order.

If a folder[i] is located within another folder[j], it is called a sub-folder of
it. A sub-folder of folder[j] must start with folder[j], followed by a "/". For
example, "/a/b" is a sub-folder of "/a", but "/b" is not a sub-folder of
"/a/b/c".

The format of a path is one or more concatenated strings of the form: '/'
followed by one or more lowercase English letters.

- For example, "/leetcode" and "/leetcode/problems" are valid paths while an
empty string and "/" are not.
*/

public class Solution
{
    public IList<string> RemoveSubfolders(string[] folder)
    {
        // Initialise to dictionary with strings -> key, and value to the count
        // There will be an exception if there are duplicate keys
        // If this exists in the test data use .Distinct first
        // No duplicate paths found in test cases, so we can reduce to a HashSet
        HashSet<string> paths = new HashSet<string>(folder);

        List<string> res = new List<string>();
        foreach (var f in folder)
        {
            List<string> dirNames = f.Split('/').Where(x => !string.IsNullOrEmpty(x)).ToList<string>();
            bool isSubDir = false;
            // It can't be a sub-dir if there's only 1 dir.
            if (dirNames.Count != 1)
            {
                // Check if this entry is a subdir of any others in the dict.
                // For this we need to gradually combine from the root up and test
                // each combination, e.g. '/a/b/c/d` we should test `/a`, `/a/b`, `/a/b/c`
                string baseDir = "";
                for (int i = 0; i < dirNames.Count-1; i++)
                {
                    baseDir += "/" + dirNames[i];
                    if (paths.Contains(baseDir))
                    {
                        isSubDir = true;
                        break;
                    }
                }
            }
            // Now we know the result of whether it was a subdir of something
            // in the dictionary or not, so add if we're good
            if (!isSubDir)
            {
                res.Add(f);
            }
        }

        return res;
    }
}

public class Program
{
    public static int Main(string[] args)
    {
        Console.WriteLine("1233-remove-sub-folders-from-filesystem\n");

        string[] folder = [ "/a","/a/b","/c/d","/c/d/e","/c/f" ];
        string[] exp = [ "/a","/c/d","/c/f" ];

        Solution sol = new Solution();
        List<string> res = new List<string>(sol.RemoveSubfolders(folder));

        Console.Write("Input: folder = [ ");
        foreach (var f in folder)
        {
            Console.Write("'{0}' ", f);
        }
        Console.WriteLine("]");
        Console.Write("Output: res = [ ");
        foreach (var f in res)
        {
            Console.Write("'{0}' ", f);
        }
        Console.WriteLine("]");

        return 0;
    }
}
