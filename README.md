# About

Some assorted [Leetcode problems](https://leetcode.com/problems)

Mostly using C++ or C#

Nothing fancy, individual standalone solutions

# Compile and Run

## C++

```bash
g++ program.cc -std=c++23 -Wall && ./a.out
```

## C#

```bash
cd 123-problem-name/
dotnet run
```

# Adding New Problems

## C++

- Create standalone `.cc` file and compile

## C#

```
dotnet new console -n 123-problem-name
cd 123-problem-name
dotnet sln ../leetcode.sln add 123-problem-name.csproj
```

# Notable Examples

- [2044-count-num-max-bitwise-or-subsets](2044-count-num-max-bitwise-or-subsets/program.cc)
    - Use an incrementing binary number as a bitmask to select all possible permutations of the elements of an array
    - I.e. for an array size 8, we want to generate all combinations of indices from `00000001` to `11111111`

# TODO

- Make this a proper project so we can re-use code via importing headers of previous solutions
    - How to handle C# / C++? 2 separate directories and projects?

