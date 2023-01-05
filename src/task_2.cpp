#include <iostream>
#include <vector>
#include <memory>

using namespace std;

class Animal {
public:
    virtual ~Animal() = default;

    virtual string makeNoise() = 0;
};

class Elephant : public Animal {
public:
    string makeNoise() override {
        return "Toot!";
    }
};

class Pig : public Animal {
public:
    string makeNoise() override {
        return "Honk!";
    }
};

int main() {
    vector<unique_ptr<Animal>> animals;
    animals.emplace_back(make_unique<Elephant>());
    animals.emplace_back(make_unique<Elephant>());
    animals.emplace_back(make_unique<Pig>());


    for(auto const &a : animals) {
        cout << a -> makeNoise() << endl;
    }


    return 0;
}

/*
Correct printout:
Toot!
Toot!
Honk!
*/
