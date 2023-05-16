#include <iostream>
using namespace std;

class container {

	int size;
public:
	float* p;
	container(int s) :size(s){}
	const int& getsize() { return size;}

};

class vector :public container {

	int call_num;
public:
	explicit vector(int l) :len(l),container(1 * 100){
		p = new float();
	}
	int len;
	const int& getlen() const {
		return len;
	}
	~vector() = default;
};

int main() {

	container c1(100);
	vector v1(10);
	container& r1 = v1;
	container c2 = 100;
	c2.getsize();
	cout << c2.getsize();
	vector v2(100);
	//v2.getlen = 40; ////this dosn't work because type of function is 'const int'
	cout << v2.getlen();
}