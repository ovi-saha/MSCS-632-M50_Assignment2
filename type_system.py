# Python: Type System, Scope, and Closure Demonstration

# Dynamic Typing (Type System)
def add(a, b):
    return a + b  # No explicit type enforcement

print("Integer Addition:", add(5, 10))   # Output: 15
print("String Concatenation:", add("Hello", " World"))  # Output: Hello World

# Scope: LEGB Rule (Local → Enclosing → Global → Built-in)
x = 10  # Global Scope

def outer_function():
    x = 5  # Enclosing Scope
    
    def inner_function():
        x = 3  # Local Scope
        print("Inner:", x)  # Output: 3
    
    inner_function()
    print("Outer:", x)  # Output: 5

outer_function()
print("Global:", x)  # Output: 10

# Closure: Inner function remembers variable from outer function
def closure_example(x):
    def inner(y):
        return x + y
    return inner

add_five = closure_example(5)
print("Closure Output:", add_five(10))  # Output: 15
