#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the jumpingOnClouds function below.
/*
 * c = [0, 1, 0, 0, 0, 1, 0]
 * Cannot land on '1's.
 * Start at index 0.
 * Can jump from index i to either i+1 or i+2, so long
 * 	as i+1 or i+2 != 1.
 * What is the minimum number of jumps possible to
 *  land on the last cloud (win the game).
 * Assumption: Every game is winnable.
 * 
 */ 
int jumpingOnClouds(vector<int> c) {
	// Greedy attempt:
	size_t place = 0;
	size_t victory = c.size() - 1;
	int jumpCount = 0;
	while (place != victory)
	{
		if (place+2 <= victory && c[place+2] != 1)
			place += 2;
		else
			place +=1;
		// This is fine since every game is assumed winnable.
		++jumpCount;
	}
	return jumpCount;
}

int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string c_temp_temp;
    getline(cin, c_temp_temp);

    vector<string> c_temp = split_string(c_temp_temp);

    vector<int> c(n);

    for (int i = 0; i < n; i++) {
        int c_item = stoi(c_temp[i]);

        c[i] = c_item;
    }

    int result = jumpingOnClouds(c);

    cout << result << endl;

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
