#include <iostream>
using namespace std;

class container {

	int size;
public:
	float* p;
	container(int s) :size(s) {}
	const int& getsize() { return size; }
	void setsize(int x) { size = x; }
};

class  vector :public container {

	static int call_num;
public:
	explicit vector(int l) :len(l), container(1 * 100) {
		p = new float();
	}
	int len;
	int& getlen() {
		call_num++;
		return len;
	}
	vector(int l) :len(l), container(1 * 100)
	{
		p = new float();

	}
	~vector() = default;

};

int main() {

	container c1(100);
	vector v1(0); 
	v1.setsize(100);
	container& r1 = v1;
	container c2 = 100;
	c2.setsize(20);
	cout << c2.getsize();
	vector v2(100);
	v2.getlen() = 40;
	cout << v2.getlen();
}