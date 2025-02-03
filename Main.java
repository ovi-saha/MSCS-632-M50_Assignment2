public class Main {
    public static void main(String[] args) {
        // Create an array of Integer objects with a size of 5
        Integer[] numbers = new Integer[5]; // The array is created, and it holds Integer objects

        // Assign values to the array
        for (int i = 0; i < 5; i++) {
            numbers[i] = i; // Assigning values (0, 1, 2, 3, 4) to the array elements
        }

        // Print the first element of the array (which is 0)
        System.out.println(numbers[0]); // Output will be 0
    } // At the end of the method, the array 'numbers' will go out of scope
} // Memory for the array and its elements will be cleaned up by the garbage collector later
