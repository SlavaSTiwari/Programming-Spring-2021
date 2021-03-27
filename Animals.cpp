#include<iostream>

using namespace std;

class Animal
{
public:
    string name;
    int age;
    int weight;

    void set_name(string s)
    {
        name = s;
    }

    void set_age(int a)
    {
        age = a;
    }

    void set_weight(int w)
    {
        weight = w;
    }
};

class Cat: public Animal
{
    void say(){
        printf("Mew!");
    }

};

class Dog: public Animal
{
    void say(){
        printf("Bork!");
    }

};class Kangaroo: public Animal
{
    void say(){
        printf("Hello human!");
    }
};



int main()
{
    Cat alice;

    alice.set_age(3);

    alice.say();


    return 0;
}
