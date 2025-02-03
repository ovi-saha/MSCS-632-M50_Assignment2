#include <iostream>
#include <ctime> // For clock()
#include <sys/resource.h> // For getrusage()

using namespace std;

int main() {
    // Start measuring the time
    clock_t start_time = clock();

    // Dynamically allocate memory for an integer and initialize it to 42
    int* ptr = new int(42); // 'ptr' now points to a dynamically allocated integer with value 42

    // Measure memory usage before printing
    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);
    long memory_before = usage.ru_maxrss; // Maximum resident set size (in kilobytes)

    // Dereference 'ptr' to access the value it points to and print it
    cout << "Dynamically allocated value: " << *ptr << endl; // Output will be 42

    // Free the dynamically allocated memory
    delete ptr; // Memory allocated by 'new' is manually released using 'delete'

    // Measure memory usage after deallocation
    getrusage(RUSAGE_SELF, &usage);
    long memory_after = usage.ru_maxrss; // Maximum resident set size (in kilobytes)

    // Calculate the total time taken
    clock_t end_time = clock();
    double time_taken = double(end_time - start_time) / CLOCKS_PER_SEC; // Time in seconds

    // Output the memory usage and time taken
    cout << "Memory usage before deallocation: " << memory_before << " KB" << endl;
    cout << "Memory usage after deallocation: " << memory_after << " KB" << endl;
    cout << "Time taken for execution: " << time_taken << " seconds" << endl;

    return 0; // End of program, 'ptr' is no longer valid after 'delete'
}
