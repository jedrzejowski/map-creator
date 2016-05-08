#include <stdio.h>

class foo {
public:
    virtual int a() { return 1; }
};

class bar : public foo {
public:
    virtual int a() { return 2; }
};

int main() {
    auto b = bar();
    auto a = dynamic_cast<foo*>(&b);
    printf("%d\n", a->a());
    return 0;
}