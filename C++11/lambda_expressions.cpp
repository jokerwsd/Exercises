//Lambda Expressions
#include <iostream>
#include <vector>
#include <algorithm>
/*
Template:
[ capture clause ] (parameters) -> return-type
{
	definition of method
}
*/

//use by itself
using namespace std;

int main()
{
	//basic usage, supported by C++ 14
	//with auto input and return value
	vector<int> arr {2,5,7,1,8,2,9};

	auto add = [](auto a, auto b)
	{
		return a + b;
	};

	//can be used to enhance the std lib
	//sort decrease order 

	//change value in arr, access by reference
	for_each(arr.begin(), arr.end(), [](int &a){ ++a; });


	sort(arr.begin(), arr.end(), [](const int& a, const int& b)->bool{return a>b;});

	//another example of enhancing for_each function to print value in container
	for_each(arr.begin(), arr.end(), [](const int a) {cout << a << ' ';});

	cout << endl;



	int a, b;
	cout << "input number to add " << endl;
	cin >> a >> b;
	cout <<  add(a , b) << endl;
	return 0;
}