#include <iostream>
#include <thread>
#include <string>

class Child {
    public:
    std::string name;
    Child(std::string name) : name{name} {};
    void operator () (int &x) {
        std::string msg {std::to_string(x)};
        if (x % 15 == 0) {
            msg = "fizzbuzz";
        } else if (x % 3 == 0) {
            msg = "fizz";
        } else if (x % 5 == 0) {
            msg = "buzz";
        }
        std::cout << name << " says " << msg << std::endl;
    }
};

int main() {
    // Abdul says 1
    // Bart says 2
    // Claudia says fizz!
    // Divya says 4
    Child abdul {"Abdul"};
    Child bart {"Bart"};
    Child claudia {"Claudia"};
    Child divya {"Divya"};
    int x {};
    Child list[] {abdul, bart, claudia, divya};
    for (x = 1; x < 5; x++) {
        std::thread t1 {list[1], std::ref(x)};
        t1.join();
    }
    return 0;
}