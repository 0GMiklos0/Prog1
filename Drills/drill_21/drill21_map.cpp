#include <iostream>
#include <map>
#include <string>
#include <numeric>
#include <stdexcept>

template<typename K, typename V>
void print(const std::map<K, V>& m)
{
	for(std::pair<K, V> i : m)
	{
		std::cout << i.first << '\t' << i.second << std::endl;
	}
}

void read_map(std::map<std::string, int>& m)
{
	std::string s;
	int i = 0;
	while(m.size()<10)
	{
		std::cin >> s >> i;
		//m[s] = i;
		//felulirja az azonos kulcsu ertekeket
		m.insert(std::make_pair(s, i));
		//azonos kulcsu ertekeket eldobja
	} 
}

int main()
try {
	std::map<std::string, int> msi;
	msi["a"] = 1;
	msi["b"] = 3;
	msi["ab"] = 7;
	msi["efgh"] = 98;
	msi["xy"] = 76;
	msi["qw"] = 61;
	msi["efh"] = 60;
	msi["xc"] = 23;
	msi["qwertz"] = 11;
	msi["ax"] = 1;
	//std::pair
	
	//kiiratas
	
	std::cout << "MSI map:\n";
	print(msi);
	
	//torles
	/*
	msi.erase("a");
	std::cout << "MSI map without a:\n";
	print(msi);
	
	msi.erase(msi.begin(), msi.end());
	std::cout << "MSI map deletion:\n";
	print(msi);
	
	//beolvasas
	
	std::cout << "Making new pairs:\n";
	read_map(msi);
	std::cout << "MSI new map:\n";
	print(msi);
	*/
	
	//ertekek osszeadasa
	
	int sum=0;
	for(std::pair<std::string, int> i : msi)
	{
		sum+=i.second;
	}
	std::cout << "The sum of MSI map's values: " << sum << '\n';
	//mis map

	std::map<int, std::string> mis;
	for(std::pair<std::string, int> i : msi)
	{
		mis[i.second] = i.first;
	}
	std::cout << "MIS map:\n";
	print(mis);
	
	
	
	

} catch(std::exception& e) {
	std::cerr << "exception: " << e.what() << '\n';
	return 1;
} catch(...) {
	std::cerr << "unknown\n";
	return 2;
}
