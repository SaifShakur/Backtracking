# Backtracking
A program that demonstrates the backtracking algorithm to encrypt a target string.
The target string is given by the user, in addition to a set of elements.
The program recursively concatenates the elements to determine whether or not the 
the target string can be encrypted based on the indices of the vector storing the elements.

NOTE: We assume valid input for the target string, set size, and elements.

Example : Target string is “abbccca”. Elements set has 3 strings in it: “a”, “bb” and “ccc” (in this order). 
So the output shows 0 1 2 0 because “abbccca” is “a”+”bb”+”ccc”+”a”.



