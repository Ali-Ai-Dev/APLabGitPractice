#include <iostream>z
using namespace std;

class container
{

	int size;

public:
	float *p;
	container(int s) : size(s) {}
	const int &getsize() { return size; }
};

class vector : public container
{

	int call_num;

public:
	explicit vector(int l) : len(l), size(1 * 100)
	{
		p = new float();
	}
	int len;
	int &getlen() const
	{
		call_num++;
		return len;
	}
	~vector() = default;
};

int main()
{

	container c1(100);
	// vector v1 = c1;  // attempting to assign base class object to derived class object
	container &r1 = v1;
	container c2 = 100;
	// c2.getsize() = 20;  // attempting to modify the constant reference
	cout << c2.getsize();
	//vector v2 = 100;  //ambigous
	// v2.getlen = 40; //	v2.getlen();

	cout << v2.getlen();
	return 0;
}