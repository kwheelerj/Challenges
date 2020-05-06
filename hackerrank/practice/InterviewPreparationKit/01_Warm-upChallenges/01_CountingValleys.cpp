#include <bits/stdc++.h>

using namespace std;

// Complete the countingValleys function below.
int countingValleys(int n, string s) {
	int level = 0;
	int valleyCount = 0;
	for (auto c : s)
	{
		int beforeLevel = level;
		if (c == 'D')
			--level;
		else if (c == 'U')
			++level;
		if (level == 0)	// out of valley / off of mountain
		{
			if (beforeLevel < 0)
				++valleyCount;
		}
	}
	return valleyCount;
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    int result = countingValleys(n, s);

    cout << result << endl;

    return 0;
}
