#include<bits/stdc++.h>

using namespace std;

class Animal
{
    private:
        string name;
        int age;
        int weight;

    public:
        // Constructors:
        Animal(){
            name = "no name";
            age = 0;
            weight = 0;
        }

        Animal(string aName, int aAge, int aWeight){
            name = aName;
            age = aAge;
            weight = aWeight;
        }

        // Setters:
        void set_name(string aName){
            name = aName;
        }
        void set_age(int aAge) {
            age = aAge;
        }
        void set_weight(int aWeight) {
            weight = aWeight;
        }

        // Getters:
        string get_name() {
            return name;
        }
        int get_age() {
            return age;
        }
        int get_weight() {
            return weight;
        }

        // Virtual function for polymorphism:
        virtual void say()=0;

};

class Cat: public Animal
{
    public:
        void say(){
            cout << "Mew!" << endl;
        }
};

class Dog: public Animal
{
    public:
        void say(){
            cout << "Bork!" << endl;
        }
};

class Kangaroo: public Animal
{
    public:
        void say(){
            cout << "Hello hooman!" << endl;
        }
};

//Function prototypes:
void generate_list(vector<Animal *> &vec, int c);
void print_list(vector<Animal *> vec);
void say_all(vector<Animal *> &vect);
void five_fat_cats(vector<Animal *> &vect);

string random_name();

int main()
{
    srand(time(0));
    int max_count = rand()%(50-20+1)+20;
    int i;

    // 1. Making "Animals" and using the method say():
    Cat Mittens;
    Dog Dawko;

    Mittens.say();
    Dawko.say();

    // 2. Making generated list of random Animal(s):
    vector<Animal *> a1;

    generate_list(a1, max_count);
    print_list(a1);

    // 4. ".say()" for the entire list:
    say_all(a1);

    // 3. Using sort function to find the fattest Animal:
    std::sort(a1.begin(), a1.end(), [](Animal* a, Animal* b) {
        return a->get_weight() < b->get_weight();
    });

    cout << "\nThe fattest animal is: " << a1.back()->get_name() << " with weight a of: " << a1.back()->get_weight() << "Kgs" << endl;

    // 5. Finding the five fattest cats:
    five_fat_cats(a1);

    return 0;
}

void generate_list(vector<Animal *> &vec, int c){
    int i;
    for(i=0;i<c;i++){
        int x = rand();
        string ran_name = random_name();

        if(x%3 == 0) {
            Animal *cat = new Cat;
            cat->set_name(ran_name + "-Cat");
            cat->set_age((rand()%(16-9+1))+9);
            cat->set_weight((rand()%(12-7+1))+7);
            vec.push_back(cat);
        }
        if(x%3 == 1) {
            Animal *dog = new Dog;
            dog->set_name(ran_name + "-Dog");
            dog->set_age((rand()%(13-10+1))+10);
            dog->set_weight((rand()%(45-21+1))+21);
            vec.push_back(dog);
        }
        if(x%3 == 2) {
            Animal *kang = new Kangaroo;
            kang->set_name(ran_name + "-Kangaroo");
            kang->set_age((rand()%(20-14+1))+14);
            kang->set_weight((rand()%(58-39+1))+39);
            vec.push_back(kang);
        }
    }
}

void print_list(vector<Animal *> vec) {

    for(int i=0; i<vec.size(); i++){
        cout << vec[i]->get_name() << endl;
        cout << vec[i]->get_age() << endl;
        cout << vec[i]->get_weight() << "\n" << endl;
    }

}

void say_all(vector<Animal *> &vect) {

    cout << "The animals say:" << endl;

    for(int i=0; i<vect.size(); i++) {
        vect[i]->say();
    }

}

void five_fat_cats(vector<Animal *> &vect) {

    int c = 0;

    cout << "\nThe 5 fattest cats are:" << endl;
    for(int i=vect.size(); i>0; i--) {
        if(dynamic_cast<Cat *>(vect[i]) != nullptr && c < 5) {
            cout << vect[i]->get_name() << " with a weight of: " << vect[i]->get_weight() << endl;
            c++;
        }
    }

}

string random_name(){

    int c;
    string name("");
    char cons[] = "bcdfghjklmnpqrstwvxyz";
    char vow[] = "aeiou";

    for(c=0;c<2;c++) {
        name += cons[rand()%21];
        name += vow[rand()%5];
    }

    return name;
}
