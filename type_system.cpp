#include <iostream>
using namespace std;

// Static Typing (Type System)
int add(int a, int b) {
    return a + b;
}

int main() {
    cout << "Integer Addition: " << add(5, 10) << endl; // Output: 15
    // cout << add("Hello", "World"); // Compilation Error: Incompatible Types

    // Scope: Global, Function, Block Scope
    int x = 10; // Global Scope

    auto outerFunction = [&]() {
        int x = 5; // Function Scope

        {
            int x = 3; // Block Scope
            cout << "Inner: " << x << endl; // Output: 3
        }

        cout << "Outer: " << x << endl; // Output: 5
    };

    outerFunction();
    cout << "Global: " << x << endl; // Output: 10

    // Closure: Lambda function capturing a variable
    auto closureExample = [](int x) {
        return [x](int y) { return x + y; };
    };

    auto addFive = closureExample(5);
    cout << "Closure Output: " << addFive(10) << endl; // Output: 15

    return 0;
}
