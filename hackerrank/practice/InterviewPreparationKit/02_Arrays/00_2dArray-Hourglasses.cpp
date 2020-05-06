#include <bits/stdc++.h>

using namespace std;

// Complete the hourglassSum function below.
int hourglassSum(vector<vector<int>> arr) {
	int max = std::numeric_limits<int>::min();
	int sum = 0;
	for (size_t i = 0; i != 4; ++i)
	{
		for (size_t j = 0; j != 4; ++j)
		{
			sum = arr[i][j] + arr[i][j+1] + arr[i][j+2]
							+ arr[i+1][j+1]
				+arr[i+2][j] + arr[i+2][j+1] + arr[i+2][j+2];
			if (sum > max)
				max = sum;
		}
	}
	return max;
}

int main()
{
    vector<vector<int>> arr(6);
    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);

        for (int j = 0; j < 6; j++) {
            std::cin >> arr[i][j];
        }


        std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    for (int i = 0; i < 6; i++) {
    	for (int j = 0; j < 6; j++) {
   	     std::cout << arr[i][j] << " | ";
 		}
		 std::cout << std::endl;
    }

    int result = hourglassSum(arr);

    std::cout << result << std::endl;

    return 0;
}
