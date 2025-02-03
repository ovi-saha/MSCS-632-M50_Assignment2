use std::time::Instant;
use std::process::Command;

fn main() {
    // Start time measurement
    let start_time = Instant::now();

    // Get memory usage before allocation (using system command `ps`)
    let output_before = Command::new("ps")
        .arg("-o")
        .arg("rss=")
        .arg(format!("{}", std::process::id())) // Get current process ID
        .output()
        .expect("Failed to execute command");

    let memory_before: usize = String::from_utf8_lossy(&output_before.stdout)
        .trim()
        .parse()
        .unwrap_or(0);

    // Create a new empty vector
    let mut vec = Vec::new(); // vec owns the vector

    // Ownership of the vector is moved to vec2
    let mut vec2 = vec; // Ownership transfer occurs, `vec` can no longer be used after this line

    // We can now modify vec2 (since it's mutable)
    vec2.push(10); // Mutating vec2 (adding an element to the vector)

    // Print the contents of vec2
    println!("{:?}", vec2); // Ownership remains with vec2, which now contains [10]

    // Get memory usage after allocation
    let output_after = Command::new("ps")
        .arg("-o")
        .arg("rss=")
        .arg(format!("{}", std::process::id()))
        .output()
        .expect("Failed to execute command");

    let memory_after: usize = String::from_utf8_lossy(&output_after.stdout)
        .trim()
        .parse()
        .unwrap_or(0);

    // Measure the time taken
    let elapsed_time = start_time.elapsed();

    // Output memory usage and time taken
    println!("Memory usage before allocation: {} KB", memory_before);
    println!("Memory usage after allocation: {} KB", memory_after);
    println!("Time taken for execution: {:.6} seconds", elapsed_time.as_secs_f64());
}
