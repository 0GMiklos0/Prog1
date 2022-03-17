#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Person
{
	Person(string fn, string ln, int a):first_name{fn}, age{a}, last_name{ln} 
	{
		for(char c : fn, ln)	
		{
			switch(c)
			case ';':
			case ',':
			case '"':
			case '\'':
			case '[':
			case ']':
			case '*':
			case '&':
			case '^':
			case '%':
			case '$':
			case '#':
			case '@':
			case '!': throw runtime_error("Invalid character in person");
		}
	}
	int a() const {return age;}
	string fn() const {return first_name;}
	string ln() const {return last_name;}
private:
	int age;
	//string name;
	string first_name;
	string last_name;
};

istream& operator>>(istream& is, Person& p)
{
	string fn, ln;
	int a;
	
	is >> fn >> ln >> a;
	p = Person(fn, ln, a);
	return is;
}

ostream& operator<<(ostream& os, const Person& p)
{
	return os << p.fn() << ' ' << p.ln() << ' ' << p.a() << '\n';
}

int main()
try {
	Person p1("Goofy", "Grand", 63);
	
	cout<<p1;
	
	vector<Person> vec;
	for(Person p;cin>>p;)
	{
		if(p.fn() == "end") break;
		vec.push_back(p);
	}
} catch(exception& e) {
	cerr << e.what() << endl;
}
