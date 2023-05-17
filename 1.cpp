#include <iostream>

using namespace std;

class container {
protected:
    int size;
public:
    float *p;

    container(int s) : size(s) {}

    container() = default;

    const int &getsize() { return size; }

    void setSize(int x) { size = x ;}
};

class vector : public container {
    int call_num;
public:
    explicit vector(int l) : len(l) {
        size = 1 * 100;
        p = new float();
    }

    vector &operator=(container x) {
        vector y(1);
        y.setSize(x.getsize());
        y.p = x.p;
        y.len = 1;
        return y;
    }

    vector() = default;

    int len;

    int getlen() {
        call_num++;
        return len;
    }

    ~vector() = default;
};

int main() {

    container c1(100);
    vector v1;
    v1 = c1;
    container &r1 = v1;
    container c2 = 100;
    c2.setSize(20);
    cout << c2.getsize();
    vector v2 (100);
    v2.len = 40;
    cout << v2.getlen();
}