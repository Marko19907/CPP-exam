#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

template <typename T>
string concat(T x, T y) {
    stringstream stream;
    stream << x << y;
    return stream.str();
}

template <typename T>
string concat(initializer_list<T> initializerList) {
    stringstream stream;
    for (const auto &i : initializerList)
        stream << i;
    return stream.str();
}

int main() {
    cout << concat("hello", "world") << endl;
    cout << concat(1, 2) << endl;
    cout << concat({"a", "b", "c"}) << endl;

    return 0;
}

/*
Correct printout:
helloworld
12
abc
*/
