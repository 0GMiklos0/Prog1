#include <iostream>
#include <vector>
#include <stdexcept>
#include <fstream>
#include <set>
#include <numeric>
#include <algorithm>

template<typename C>
void print(const C& c, char sep = '\n')
{
	std::cout << "Container elements:\n" ;
	
	for(const auto elem : c)
	{
		std::cout << elem << std::endl;
	}
	std::cout << '\n';
}

/*class Less_than {
	double v;
	public:
	Less_than():{}
	bool operator(){}
	
};funktoros megoldas*/

int main()
try {
	const std::string iname {"input_floats.cpp"};
	std::ifstream ifs {iname};
	if(!ifs) throw std::runtime_error("Couldnot read file: " + iname);
	
	std::vector<double> vd;
	for(double d; ifs >> d;)
	{
		vd.push_back(d);
	}
	
	print(vd);
	
	std::vector<int> vi(vd.size()); // meretezes nelkul nem mukodnde a copy-val
	/*for(auto& i : vd)
	{
		vi.push_back(i);
	}*/
	std::copy(vd.begin(), vd.end(), vi.begin());
	print(vi);
	
	for(int i = 0; i < vd.size() ; i++) { std::cout << vd[i] << ' ' << vi[i] << '\n'; }
	
	double sum=0;
	//sum = std::accumulate(vi.begin(),vi.end(),0.0)
	for(int i = 0; i < vd.size(); i++) { sum+=vd[i]-vi[i]; }
	
	std::cout << "The sum of the difference: " << sum << '\n';
	
	std::reverse(vd.begin(), vd.end());
	print(vd);
	
	double davg = std::accumulate(vd.begin(), vd.end(), 0.0) / vd.size();
	std::cout << davg << '\n';
	
	//Atlagnal kisebb szamok masolasa
	
	std::vector<double> vd2(vd.size());
	std::copy_if(vd.begin(),vd.end(),vd2.begin(),[+](double d){return d < davg;});
	
	vd2.resize(std::distance(vd2.begin(), it));
	std::sort(vd.begin(), vd.end());
	
	
		
} catch (std::exception& e) {
	std::cerr << "error: " << e.what() << '\n';
	return 1;
} catch (...) {
	std::cerr << "unknown\n";
	return 2;
}
