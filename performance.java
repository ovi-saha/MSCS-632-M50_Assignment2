public class Main {
    public static void main(String[] args) {
        // Start time measurement
        long startTime = System.nanoTime();
        
        // Get the initial memory usage
        Runtime runtime = Runtime.getRuntime();
        long memoryBefore = runtime.totalMemory() - runtime.freeMemory(); // in bytes

        // Create an array of Integer objects with a size of 5
        Integer[] numbers = new Integer[5]; // The array is created, and it holds Integer objects

        // Assign values to the array
        for (int i = 0; i < 5; i++) {
            numbers[i] = i; // Assigning values (0, 1, 2, 3, 4) to the array elements
        }

        // Print the first element of the array (which is 0)
        System.out.println(numbers[0]); // Output will be 0

        // Get the memory usage after the allocation
        long memoryAfter = runtime.totalMemory() - runtime.freeMemory(); // in bytes

        // Measure the time taken
        long endTime = System.nanoTime();
        double timeTaken = (endTime - startTime) / 1_000_000.0; // Convert to milliseconds

        // Output memory usage and time taken
        System.out.println("Memory usage before allocation: " + memoryBefore + " bytes");
        System.out.println("Memory usage after allocation: " + memoryAfter + " bytes");
        System.out.println("Time taken for execution: " + timeTaken + " ms");
    }
}
