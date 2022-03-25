#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <array>
#include <list>

using namespace std;

template<typename C>
void print(const C& c) 
{
	for(auto& i:c)
	{
		cout << c[i] << ' ';
	}
	cout << '\n';
}

template<typename C>
void inc(C& c, int n) 
{
	for(auto& i:c)
	{
		i+=n;
	}
}

//template<typename Iter1, typename Iter2>

int main()
try {	
	constexpr int size = 10;
	
	int arr[size] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	
	array<int, size> ai;
	copy(arr, arr + size, ai.begin());
	
	vector<int> vi(size);
	copy(arr, arr + size, vi.begin());
	
	list<int> li(size);
	copy(arr, arr + size, li.begin());
	
	print(ai);
	print(vi);
	print(arr);
	print(li);
	
	inc(ai, 4);
	print(ai);
	
	/*orai_copy(ai.begin(), ai.end(), vi2.begin());
	orai_copy(li.begin(), li.end(), ai2.begin());
	array<int, size> ai2 = ai;
	vector<int> vi2 = vi;
	list<int> li2 = li;*/
	
	vector<int>::iterator vit;
	vit = find(vi2.begin(), vi2.end(), 27);
	if(!vit = vi2.end() {
		cout << "Found at: " << distance(vi2.begin(), vit) << endl;
	}
	else 
	{
		cout << "not found\n";
	}
	
} catch(...) {
	cerr << "unknown\n";
}
