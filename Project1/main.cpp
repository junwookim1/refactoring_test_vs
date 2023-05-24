#include<iostream>
#include<vector>
#include<string>
using std::cout;
using std::string;
using std::vector;

vector<string> split(string& text)
{
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
	return values;
}

int sum_values(vector<string>& values)
{
	int result = 0;
	// sum 
	for (int i = 0; i < values.size(); i++) {
		int temp = stoi(values[i]);
		result += temp;
	}
	return result;
}

int splitAndSum2(string text)
{
	if (text.empty())
	{
		return 0;
	}

	vector<string> values = split(text);
	return sum_values(values);

}
int main()
{
	cout << splitAndSum2("100-10-20");
	return 0;
}