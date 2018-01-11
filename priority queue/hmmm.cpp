#include <fstream>
#include <vector>
#include <iostream>

using namespace std;


class Heap
{
	struct Node
	{
		int key, index;
	};

	vector<Node> v;

public:
	void shiftDown(int i)
	{
		while (i < v.size())
		{
			int left = 2 * i + 1;   //children of element
			int right = 2 * i + 2;
			int largestChild = left;			//element

			if (largestChild >= v.size()) //check overflow
				break;

			if (right < v.size() && v[right].key < v[left].key)
				largestChild = right;

			if (v[i].key < v[largestChild].key)
				break;

			Node t = v[i];  //on i place put largest element
			v[i] = v[largestChild];
			v[largestChild] = t;

			i = largestChild;
		}
	}

	void shiftUp(int i) //element>parent
	{
		while (i > 0 && v[i].key < v[(i - 1) / 2].key)
		{
			Node t = v[i];
			v[i] = v[(i - 1) / 2];
			v[(i - 1) / 2] = t;

			i = (i - 1) / 2;
		}
	}

	void push(Node x)
	{
		v.push_back(x);
		shiftUp(v.size() - 1);
	}


	int extract_min()
	{
		if (v.size() < 1)
		{
			return NULL;
		}

		int min = v[0].key;
		v[0] = v.back();
		v.pop_back();
		shiftDown(0);
		cout << min << endl;
		return min;
	}

	

};

int main()
{

	Heap h;
	int x, key;


	int n = 3;

	for (int i = 0; i<n; i++)
	{
		cin >> x;
		h.push({ x,i });
	}

	return 0;
}
