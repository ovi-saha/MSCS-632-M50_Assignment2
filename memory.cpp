#include <iostream>
using namespace std;

int main() {
    // Dynamically allocate memory for an integer and initialize it to 42
    int* ptr = new int(42); // 'ptr' now points to a dynamically allocated integer with value 42

    // Dereference 'ptr' to access the value it points to and print it
    cout << "Dynamically allocated value: " << *ptr << endl; // Output will be 42

    // Free the dynamically allocated memory
    delete ptr; // Memory allocated by 'new' is manually released using 'delete'

    return 0; // End of program, 'ptr' is no longer valid after 'delete'
} // At this point, memory has been freed and 'ptr' is now a dangling pointer
