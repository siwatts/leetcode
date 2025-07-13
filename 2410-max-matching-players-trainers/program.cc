#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
You are given a 0-indexed integer array players, where players[i] represents the
ability of the ith player. You are also given a 0-indexed integer array
trainers, where trainers[j] represents the training capacity of the jth trainer.

The ith player can match with the jth trainer if the player's ability is less
than or equal to the trainer's training capacity. Additionally, the ith player
can be matched with at most one trainer, and the jth trainer can be matched with
at most one player.

Return the maximum number of matchings between players and trainers that satisfy
these conditions.
*/

class Solution
{
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers)
    {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        int res = 0;

        auto plit = players.begin();
        auto trit = trainers.begin();
        while (plit != players.end() && trit != trainers.end())
        {
            if (*plit <= *trit)
            {
                res++;
                plit++;
                trit++;
            }
            else
            {
                trit++;
            }
        }

        return res;
    }
};

int main(int argc, char* argv[])
{
    cout << "2410-max-matching-players-trainers\n";

    vector<int> players = { 4,7,9 };
    vector<int> trainers = { 8,2,5,8 };

    Solution sol;
    int res = sol.matchPlayersAndTrainers(players, trainers);

    cout << "Input: players = [";
    for (auto p : players)
    {
        cout << p << ",";
    }
    cout << "], trainers = [";
    for (auto t : trainers)
    {
        cout << t << ",";
    }
    cout << "]\n";
    cout << "Output: res = " << res << "\n";

    return 0;
}