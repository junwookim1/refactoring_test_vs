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
	
	size_t a = 0;
	size_t b = 0;
	while (true)
	{
		b = text.find("-", a);
		if (b == -1) break;
		string temp = text.substr(a, b - a);
		values.push_back(temp);
		a = b + 1;
	}
	return values;
}

int get_sum(const vector<string>& values)
{
	int result = 0;
	
	for (auto& value : values)
	{
		const int temp = stoi(value);
		result += temp;
	}
	return result;
}

int split_and_sum2(string text)
{
	if (text.empty())
	{
		return 0;
	}

	const vector<string> values = split(text);
	return get_sum(values);
}

int main()
{
	cout << split_and_sum2("100-10-20");
	return 0;
}
