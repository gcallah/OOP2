/*
  der.foo(17) calls Base::foo(int) through code reuse, i.e. method inheritance
  Inclass C
 */

#include <iostream>
using namespace std;

class A
{
public:
  void a() {}
};

class B : public A
{
public:
  void a(int) {}
};

int main()
{
  B b;
  b.a();
}
