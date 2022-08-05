#pragma once
#include <string>
#include<iostream>

using namespace std;

class Fruit
{
public:
    Fruit();
    virtual void Identify();
private:
};

class Banana : public Fruit {
    void Identify();
};

class Tangerine : public Fruit {
    void Identify();
};

class Pear : public Fruit {
    void Identify();
};

