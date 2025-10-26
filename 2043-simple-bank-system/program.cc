#include <iostream>
#include <vector>

using namespace std;

/*
You have been tasked with writing a program for a popular bank that will
automate all its incoming transactions (transfer, deposit, and withdraw). The
bank has n accounts numbered from 1 to n. The initial balance of each account is
stored in a 0-indexed integer array balance, with the (i + 1)th account having
an initial balance of balance[i].

Execute all the valid transactions. A transaction is valid if:

- The given account number(s) are between 1 and n, and
- The amount of money withdrawn or transferred from is less than or equal to the
  balance of the account.

Implement the Bank class:

- Bank(long[] balance) Initializes the object with the 0-indexed integer array
  balance.
- boolean transfer(int account1, int account2, long money) Transfers money
  dollars from the account numbered account1 to the account numbered account2.
  Return true if the transaction was successful, false otherwise.
- boolean deposit(int account, long money) Deposit money dollars into the
  account numbered account. Return true if the transaction was successful, false
  otherwise.
- boolean withdraw(int account, long money) Withdraw money dollars from the
  account numbered account. Return true if the transaction was successful, false
  otherwise.
*/

class Bank
{
private:
    vector<long long> balance;
    int N;
public:
    Bank(vector<long long>& balance) :
        balance(balance)
    {
        N = balance.size();
    }

    bool transfer(int account1, int account2, long long money)
    {
        // Still need to check both accounts exist first, because withdraw
        // and deposit are separate actions
        if (account1 < 1 || account1 > N)
            return false;
        if (account2 < 1 || account2 > N)
            return false;

        if (withdraw(account1, money))
        {
            return deposit(account2, money);
        }
        else
        {
            return false;
        }
    }

    bool deposit(int account, long long money)
    {
        if (account < 1 || account > N)
            return false;

        balance[account-1] += money;
        return true;
    }

    bool withdraw(int account, long long money)
    {
        if (account < 1 || account > N)
            return false;

        if (balance[account-1] < money)
            return false;

        balance[account-1] -= money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */

int main(int argc, char* argv[])
{
    cout << "2043-simple-bank-system\n";

    vector<long long> balance = { 10, 100, 20, 50, 30 };

    Bank* obj = new Bank(balance);
    bool param_1 = obj->withdraw(3, 10);
    bool param_2 = obj->transfer(5, 1, 20);
    bool param_3 = obj->deposit(5, 20);
    bool param_4 = obj->transfer(3, 4, 15);
    bool param_5 = obj->withdraw(10, 50);

    return 0;
}

