#include<iostream>
#include<vector>
#include<Windows.h>

using namespace std;

int main()
{
	HMODULE lib = LoadLibrary("tpLib.dll");
	typedef UINT(*count)(vector<int> temp);	//определяем тип данных для хранения функции
	int count_numbers;
	vector<int> arr;
	int n = 0;
	cout << "Enter amount of numbers: " << endl; 
	cin >> n;
	for (int i = 0; i < n; i++) {
		int number;
		cin >> number;
		arr.push_back(number);
	}
	count func = (count)GetProcAddress(lib, "count");	//ссылка на функцию из dll
	cout <<"Unique numbers: " << func(arr) << endl;

}