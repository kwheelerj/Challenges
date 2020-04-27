/*
 * The longest common subsequence problem.
 * With help from Cormen, Leiserson, Rivest, and Stein's
 * "Introduction to Algorithms" (3rd Edition).
 * Chapter 15: Dynamic Programming
 */ 

#include <iostream>
#include <vector>

class Solution
{
public:
	int longestCommonSubsequence(std::string text1, std::string text2)
	{
		int arr[text1.length() + 1][text2.length() + 1];
		for (size_t i = 0; i != text1.length() + 1; ++i)
			arr[i][0] = 0;
		for (size_t j = 0; j != text2.length() + 1; ++j)
			arr[0][j] = 0;
		
		for (size_t i = 1; i != text1.length() + 1; ++i)
		{
			for (size_t j = 1; j != text2.length() + 1; ++j)
			{
				if (text1[i-1] == text2[j-1])
					arr[i][j] = arr[i-1][j-1] + 1;
				else if (arr[i-1][j] >= arr[i][j-1])
					arr[i][j] = arr[i-1][j];
				else
					arr[i][j] = arr[i][j-1];
			}
		}
		return arr[text1.length()][text2.length()];
	}
};

int main()
{
	Solution sol;
	std::string sequenceX = "ABCBDAB";
	std::string sequenceY = "BDCABA";
	int lcs = sol.longestCommonSubsequence(sequenceX, sequenceY);
	std::cout << lcs << std::endl;
}