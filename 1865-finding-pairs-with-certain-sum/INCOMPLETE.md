# About

Problem incomplete

- First iteration
    - naive loop
    - time limit exceeded
- Second iteration
    - pre-compute all sums in 2D matrix to save time on repeated counts with no addition
    - simply update the relevant row for num2 additions
    - memory limit exceeded

# Solution

- Solution lies with the problem constraints. num1 is much smaller, and immutable
- Store num2 in hashmap, to check count then check for the count of `hashmap[tot-nums1[i]` instead
- Update hashmap when given an addition

