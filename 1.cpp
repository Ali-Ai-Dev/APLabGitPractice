#include <iostream>
using namespace std;

class container
{
protected:
	int size;
	float *p;

public:
	container() {}

	container(int s) : size(s) {}
	int &getsize() { return size; }
};

class vector : public container
{

	int call_num;
	int len;

public:
	vector(int l)
	{
		len = l;
		size = 100;
		p = new float();
	}
	vector(container temp)
	{
		this->len = temp.getsize();
		call_num = 1;
		return;
	}
	int &getlen()
	{
		call_num++;
		return len;
	}
	~vector() = default;
};

int main()
{

	container c1(100);
	vector v1 = c1;
	container &r1 = v1;
	container c2 = 100;
	c2.getsize() = 20;
	cout << c2.getsize();
	vector v2 = 100;
	v2.getlen() = 40;
	cout << v2.getlen();
}

// "const" removed // "explicit" removed // "int len;" moved up // "len" and "size" constructed // constructor with container type created // const of getlen removed 
// output : 2040