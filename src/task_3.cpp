#include <functional>
#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

template <typename T, typename S>
string map_f(vector<T> list, function<S(T a)> function) {
    if (list.empty()) {
        return "{}";
    }

    stringstream ss;
    ss << "{ ";

    size_t index = 0;
    while (index < list.size() - 1) {
        ss << function(list[index]) << ", ";
        index++;
    }

    // Last index does not have a comma
    ss << function(list[index]);
    ss << " }";

    return ss.str();
}

int main() {
    cout << map_f<int, int>({1, 2, 3}, [](int a){return a * 2;}) << endl;
    cout << map_f<float, float>({1, 2.3, 3}, [](float a){return a / 2;}) << endl;
    cout << map_f<string, string>({"hello", "world"}, [](const string& s){return s + ".";}) << endl;
    cout << map_f<string, int>({"hello", "world"}, [](const string& s){return s.size();}) << endl;

    return 0;
}

/*
Correct printout:
{ 2, 4, 6 }
{ 0.5, 1.15, 1.5 }
{ hello., world. }
{ 5, 5 }
*/
