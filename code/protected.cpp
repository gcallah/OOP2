class Base {
	protected:
	void protectedMethod() { }
};

class Derived : public Base {
};

int main() {
    Base b;
    b.protectedMethod(); // line A
    Derived d;
    d.protectedMethod(); // line B
}
