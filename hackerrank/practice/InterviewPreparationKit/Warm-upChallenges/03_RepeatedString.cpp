#include <bits/stdc++.h>

using namespace std;

// Complete the repeatedString function below.
/*
 * s = 'abcac'
 * n = 10
 * How many times does letter 'a' appear?
 * n = 10 means choose 10 letters from s, repeat the string if necessary.
 * So new_s = 'abcacabcac'.
 * Answer = 4
 * 
 * My idea:
 * 
 * --Another Example--
 * s = "aba"
 * want = 'a'
 * n = 10
 * new_s = "abaabaabaa"
 * Answer = 7
 * ----
 * At indexes: 0,2,3,5,6,8,9
 * original indexes [0,2]
 * newLengthMultiplier = n / s.length	// 3
 * remainderToAdd = n % s.length		// 1
 * need this formla:
 * 0 => 3, 6, 9
 * 2 => 5, 8
 * SIMPLE: add s.length until result >= n  
 * BUT this is slow:
 * Try a different approach, and even a different problem:
 * (n - i) / 3
 * On problem: s = "abcac", n = 10
 * 0+1 => (10 - 1) / 5 = 1 ( => 0, 5), add 1
 * 3+1 => (10 - 5) / 5 = 1 ( => 3, 8), add 1
 * ---
 * Back to s = "aba", n = 10:
 * 1 => (10-1)/3 = 3 (+1) = 4
 * 3 => (10-3)/3 = 2 )+1) = 3
 * Total = 7
 */
long long repeatedString(string s, long long n) {
	// 1. get indexes of desired character 'a' for original s
	// 2. for each index, add s.length and increment count until result >= n
	// 2 (modified) => ( (n - (index+1)) / s.length()) + 1
	if (n == 0) return 0;
	if (s.length() == 1)
	{
		if (s.front() == 'a')
			return n;
		return 0;
	}
	size_t i = 0;
	std::vector<int> indexes;
	for (auto c : s)
	{
		if (c == 'a' && i < n)
			indexes.push_back(i);
		++i;
	}
	long long count = 0LL;
	long long len = (long long) s.length();
	// for (auto i = indexes.cbegin(); i != indexes.cend(); ++i)
	// {
	// 	long long result = (long) *i;
	// 	while (result < n)
	// 	{
	// 		result += len;
	// 		++count;
	// 	}
	// }
	for (auto i = indexes.cbegin(); i != indexes.cend(); ++i)
	{
		long long subCount = 1L;	// take into account the already found 'a'
		subCount += ( (n - (*i+1)) / len );
		count += subCount;
	}
	return count;	
}

int main()
{
    string s;
    getline(cin, s);

    long  long n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long long result = repeatedString(s, n);

    cout << result << "\n";

    return 0;
}
