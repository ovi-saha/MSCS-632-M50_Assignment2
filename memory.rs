fn main() {
    // Create a new empty vector
    let vec = Vec::new(); // vec owns the vector

    // Ownership of the vector is moved to vec2
    let mut vec2 = vec; // Ownership transfer occurs, `vec` can no longer be used after this line

    // We can now modify `vec2` (since it's mutable)
    vec2.push(10); // Mutating vec2 (adding an element to the vector)

    // Print the contents of vec2
    println!("{:?}", vec2); // Ownership remains with vec2, which now contains [10]
} // Ownership transfer occurs, no manual memory management needed (Rust handles it automatically)
