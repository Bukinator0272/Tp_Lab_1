#include<Windows.h>
#include<vector>

using namespace std;

extern "C" _declspec(dllexport) UINT count(vector<int> input) {
	vector<int> temp;
	int count = 0;
	for (int i = 0; i < input.size(); i++) {
		int j = 0;
		bool check = 0;
		while (j < temp.size() && !check) {
			if (temp[j] == input[i]) check = 1;
			j++;
		}
		if (!check) {
			count++;
			temp.push_back(input[i]);
		}
	}
	return count;

}