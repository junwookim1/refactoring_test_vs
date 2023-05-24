#include<iostream>
#include<vector>
#include<string>
using std::cout;
using std::string;
using std::vector;
int splitAndSum2(string text)
{
	int result = 0;
	if (text.empty())
	{
		result = 0;
	}
	else {
		vector<string> values;
		text += "-";
		// split
		int a = 0, b = 0;
		while (1) {
			b = text.find("-", a);
			if (b == -1) break;
			string temp = text.substr(a, b - a);
			values.push_back(temp);
			a = b + 1;
		}
		// sum 
		for (int i = 0; i < values.size(); i++) {
			int temp = stoi(values[i]);
			result += temp;
		}
	}
	return result;
}
int main()
{
	cout << splitAndSum2("100-10-20");
	return 0;
}