#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the minimumBribes function below.
void minimumBribesOld(vector<int> q) {
	// first check if even valid
	for (size_t i = 0; i < q.size(); ++i)
	{
		if ( q[i] > (i+3) )
		{
			std::cout << "Too chaotic" << endl;
			return;
		}
	}
	// if not, count the bribes
	int bribeCount = 0;
	bool arr[q.size()];
	for (size_t k = 0; k < q.size(); ++k)
		arr[k] = false;
	for (size_t i = 0; i < q.size(); ++i)
	{
		/* Constraint: every number should not be ahead of a number
		 * that is lower than it. Every number we hit,
		 * we should check that all of the preceding numbers
		 * were already hit as well.  Every number that is missing
		 * is direct evidence of a bribe.
		 */
		// This won't be very great time complexity wise, but it should work.
		arr[q[i]-1] = true;
		for (size_t j = 0; j < q[i]-1; ++j)
		{
			if (!arr[j])
				++bribeCount;
		}
	}
	std::cout << bribeCount << endl;
}

int merge(vector<int>& vec, size_t beg_index, size_t mid_index, size_t end_index)
{
	int inversionCount = 0;
	size_t left_length = mid_index - beg_index + 1;
	size_t right_length = end_index - mid_index;
	vector<int> left;
	vector<int> right;
	size_t i = 0;
	size_t j = 0;
	for ( ; i < left_length; ++i)
		left.push_back(vec.at(beg_index+i));
	for ( ; j < right_length; ++j)
		right.push_back(vec.at(mid_index+j+1));
	i = j = 0;
	for (size_t k = beg_index; k < end_index+1; ++k)
	{
		if (i == left_length)	// exhausted all of left
		{
			for (size_t i2 = k; i2 < end_index+1; ++i2)
			{
				vec.at(i2) = right.at(j);
				++j;
			}
			break;
		}
		else if (j == right_length)	// exhausted all of right
		{
			for (size_t i2 = k; i2 < end_index+1; ++i2)
			{
				vec.at(i2) = left.at(i);
				++i;
			}
			break;
		}
		else
		{
			if (left.at(i) <= right.at(j))
			{
				vec.at(k) = left.at(i);
				++i;
			}
			else
			{
				vec.at(k) = right.at(j);
				inversionCount += (left_length-i);
				++j;
			}
		}
	}
	return inversionCount;
}

int countInversionsMS(vector<int>& items, size_t beg_index, size_t end_index)
{
	int inversionCount = 0;
	if (beg_index < end_index)
	{
		size_t mid_index = (beg_index + end_index) / 2;
		inversionCount += countInversionsMS(items, beg_index, mid_index);
		inversionCount += countInversionsMS(items, mid_index + 1, end_index);
		inversionCount += merge(items, beg_index, mid_index, end_index);
	}
	return inversionCount;
}

void minimumBribes(vector<int> q) {
	for (size_t i = 0; i < q.size(); ++i)
	{
		if ( q[i] > (i+3) )
		{
			std::cout << "Too chaotic" << endl;
			return;
		}
	}
	// do a modified merge sort to count the INVERSIONS
	int bribeCount = countInversionsMS(q, 0, q.size()-1);
	std::cout << bribeCount << endl;
}

int main()
{
	vector<int> v = {1, 2, 5, 3, 7, 8, 6, 4};

	for_each(v.cbegin(), v.cend(), [](const int i) {std::cout << i << " ";});
	std::cout << std::endl;

	int res = countInversionsMS(v, 0, v.size()-1);
	for_each(v.cbegin(), v.cend(), [](const int i) {std::cout << i << " ";});

	std::cout << std::endl;
	std::cout << res << std::endl;
}
int main2()
{
    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string q_temp_temp;
        getline(cin, q_temp_temp);

        vector<string> q_temp = split_string(q_temp_temp);

        vector<int> q(n);

        for (int i = 0; i < n; i++) {
            int q_item = stoi(q_temp[i]);

            q[i] = q_item;
        }

        minimumBribes(q);
    }

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
