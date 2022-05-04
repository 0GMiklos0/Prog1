#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
#include <set>

struct Fruit
{
	std::string name;
	int quantity;
	double unit_price;
	
	Fruit(const std::string& n, int q=0, double p=0) : name{n}, quantity{q}, unit_price{p}{}
};

struct Fruit_ptr_cmp
{
	bool operator()(const Fruit* a, const Fruit* b) { return a->name < b->name; }
};

int main()
try {
	//Storing in vector
	
	std::vector<Fruit> vf {
		Fruit{"Plum", 3},
		Fruit{"Grape", 13},
		Fruit{"Banana", 73},
		Fruit{"Apple", 55},
		Fruit{"Orange", 62},
		Fruit{"Cherry", 21},
		Fruit{"Plum", 43},
		Fruit{"Kiwi", 99},
	};
	
	for(auto& i : vf) 
	{
		std::cout << i.name << '\n';
	}
	
	//Using a set of pointers
	
	std::set<Fruit*, Fruit_ptr_cmp> sf;
	for(auto& f : vf)
	{
		sf.insert(&f);
	}
	std::cout << '\n';
	for(auto& i : sf)
	{
		std::cout << i->name << '\n';
	}
	
	//Drill 21
	
	
	
} catch (std::exception& e) {
	std::cerr << "error: " << e.what() << '\n';
	return 1;
} catch (...) {
	std::cerr << "unknown\n";
	return 2;
}
