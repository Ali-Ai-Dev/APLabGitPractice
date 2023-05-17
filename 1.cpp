#include <iostream>
using namespace std;

class container {

	int size;
public:
	float* p;
	container(int s) :size(s) {}
	container() { ; }
	const int& getsize() { return size; }
	void setSize(int a) { size = a; }
	
};

class vector :public container {
	int call_num;
public:
	explicit vector(int l){
		len = l;
		setSize(1 * 100);
		p = new float();
	}
	int len;
	int getlen() {
		call_num++;
		return len;
	}	
	void setlen(int a) {
		len = a;
	}
	vector() {};
	vector& operator=(container a) {
		vector a1(1);
		a1.len =1;
		a1.call_num = 0;
		a1.setSize(a.getsize());
		a1.p = a.p;
		return a1;
	}
	vector& operator=(int a) {
		setSize(a);
		return *this;
	}
	~vector() {
		delete p;
	}
};

int main() {

	container c1(100);
	vector v1;
	v1= c1;
	container& r1 = v1;
	container c2 = 100;
	c2.setSize(20);
	cout << c2.getsize();
	vector v2;
	v2= 100;
	v2.setlen(40);
	cout << v2.getlen();
}