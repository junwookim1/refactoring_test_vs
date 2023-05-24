#include<iostream>
#include<vector>
using namespace std;

class Sort
{
public:
	virtual void sort(vector<int>& arr) = 0;
};

class BubbleSort : public Sort
{
public:
	void sort(vector<int>& arr) override
	{
		for (int a = 0; a < arr.size(); a++)
		{
			for (int b = 0; b < arr.size() - 1 - a; b++)
			{
				if (arr[b] > arr[b + 1])
				{
					std::swap(arr[b], arr[b + 1]);
				}
			}
		}
	}
};

class SelectionSort : public Sort
{
public:
	void sort(vector<int>& arr) override
	{
		for (int a = 0; a < arr.size(); a++)
		{
			for (int b = a + 1; b < arr.size(); b++)
			{
				if (arr[a] > arr[b])
				{
					std::swap(arr[a], arr[b]);
				}
			}
		}
	}
};

class SortMachine
{
public:
	void insert(int val)
	{
		arr.push_back(val);
	}

	void selection(string name)
	{
		if (m_sort != nullptr)
		{
			delete m_sort;
			m_sort = nullptr;
		}
		m_sort = createSort(name);

	}
	void run()
	{
		if (m_sort == nullptr) return;
		m_sort->sort(arr);
	}
	void show()
	{
		for (const int& val : arr)
		{
			cout << val << " ";
		}
		cout << endl;
	}
private:
	Sort* createSort(string name)
	{
		if (name == "bubble")
		{
			return new BubbleSort();
		}
		if (name == "selection")
		{
			return new SelectionSort();
		}
		return nullptr;
	}
private:
	
	vector<int> arr;
	Sort* m_sort;
};


void print(vector<int>& arr)
{
	for (const int& val : arr)
	{
		cout << val << " ";
	}
	cout << endl;
}


int main()
{

	SortMachine* mixer = new SortMachine();
	mixer->insert(3);
	mixer->insert(7);
	mixer->insert(1);
	mixer->insert(5);
	mixer->insert(2);

	mixer->selection("selection");
	mixer->run();
	mixer->show();


	return 0;
}
