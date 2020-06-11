class A {
private:
    int a;
public:
    A() {this->a = 47;}
    virtual void setInt(int x) {this->a = x;}
    virtual int getInt() {return this->a;}
    ~A() {this->a = 0;}
};

class B {
private:
    int b;
public:
    B() {b = 48;}
    virtual void setInt(int x) {this->b = x;}
    virtual int getInt() {return this->b;}
    ~B() {b = 0;}
};

class C : public A, public B {
private:
    int c;
public:
    C() {c = 49;}
    virtual void setInt(int x) {this->c = x;}
    virtual int getInt() {return this->c;}
    ~C() {c = 0;}
};

int main(int argc, char const *argv[])
{
    A a;
    B b;
    C c;
    return 0;
}
