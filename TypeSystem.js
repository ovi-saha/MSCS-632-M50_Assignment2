// JavaScript: Type System, Scope, and Closure Demonstration

// Weak Typing (Type System)
function add(a, b) {
    return a + b;
}

console.log("Integer Addition:", add(5, 10));   // Output: 15
console.log("String Concatenation:", add("Hello", " World")); // Output: Hello World
console.log("Type Coercion:", add(5, "10")); // Output: "510" (String Concatenation)

// Scope: Function Scope, Block Scope (let, const)
let x = 10; // Global Scope

function outerFunction() {
    let x = 5; // Function Scope

    if (true) {
        let x = 3; // Block Scope
        console.log("Inner:", x); // Output: 3
    }

    console.log("Outer:", x); // Output: 5
}

outerFunction();
console.log("Global:", x); // Output: 10

// Closure: Inner function remembers variable from outer function
function closureExample(x) {
    return function(y) {
        return x + y;
    };
}

let addFive = closureExample(5);
console.log("Closure Output:", addFive(10)); // Output: 15
