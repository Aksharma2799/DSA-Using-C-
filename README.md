# DSA-Using-C++

### 1. What are the differences between C++ and Java?

**Answer:**
- **Memory Management:** C++ allows manual memory management using `new` and `delete`, while Java has automatic garbage collection.
- **Platform Dependency:** C++ is platform-dependent (compiled code runs on the specific OS), whereas Java is platform-independent due to the JVM (compiled bytecode runs on any OS with JVM).
- **Multiple Inheritance:** C++ supports multiple inheritance, but Java does not support it directly (uses interfaces instead).
- **Pointers:** C++ supports pointers, while Java does not have explicit pointers.
- **Performance:** C++ generally provides better performance as it is closer to hardware and does not have the overhead of JVM.

### 2. What is a virtual function in C++?

**Answer:**
A virtual function is a member function in a base class that you expect to override in derived classes. It is declared using the keyword `virtual` in the base class. When a function is made virtual, C++ determines the function to call at runtime based on the type of the object pointed to by the pointer, rather than the type of the pointer.

Example:
```cpp
class Base {
public:
    virtual void show() {
        std::cout << "Base class show function" << std::endl;
    }
};

class Derived : public Base {
public:
    void show() override {
        std::cout << "Derived class show function" << std::endl;
    }
};

int main() {
    Base* b;
    Derived d;
    b = &d;
    b->show();  // Outputs: Derived class show function
    return 0;
}
```

### 3. Explain the concept of constructors and destructors in C++.

**Answer:**
- **Constructors:** Special member functions that initialize objects of a class. They have the same name as the class and do not have a return type. Constructors can be default, parameterized, or copy constructors.
- **Destructors:** Special member functions that are executed when an object goes out of scope or is explicitly deleted. They have the same name as the class preceded by a tilde (~) and do not take parameters or return a value. Their primary role is to release resources that the object may have acquired during its lifetime.

Example:
```cpp
class MyClass {
public:
    MyClass() {
        std::cout << "Constructor called" << std::endl;
    }
    ~MyClass() {
        std::cout << "Destructor called" << std::endl;
    }
};

int main() {
    MyClass obj;  // Constructor called
    return 0;     // Destructor called
}
```

### 4. What is the difference between deep copy and shallow copy?

**Answer:**
- **Shallow Copy:** Copies all member field values. For pointers, it copies the pointer value, meaning both the original and copied objects point to the same memory location. This can lead to issues like double deletion.
- **Deep Copy:** Copies all fields, and makes copies of dynamically allocated memory pointed to by the fields. This ensures that the original and copied objects are completely independent.

Example:
```cpp
class MyClass {
public:
    int* data;

    // Constructor
    MyClass(int val) {
        data = new int(val);
    }

    // Copy Constructor for deep copy
    MyClass(const MyClass& other) {
        data = new int(*(other.data));
    }

    // Destructor
    ~MyClass() {
        delete data;
    }
};

int main() {
    MyClass obj1(10);
    MyClass obj2 = obj1;  // Deep copy
    return 0;
}
```

### 5. Explain the concept of RAII in C++.

**Answer:**
RAII (Resource Acquisition Is Initialization) is a programming idiom used in C++ where resource allocation is tied to object lifetime. Resources are acquired during object creation (initialization) and released during object destruction. This ensures resource management (e.g., memory, file handles) is handled automatically and safely.

Example:
```cpp
class FileHandle {
private:
    FILE* file;
public:
    // Constructor opens the file
    FileHandle(const char* filename) {
        file = fopen(filename, "r");
        if (!file) {
            throw std::runtime_error("File opening failed");
        }
    }

    // Destructor closes the file
    ~FileHandle() {
        if (file) {
            fclose(file);
        }
    }

    // Other member functions
};
```

### 6. What is the 'this' pointer in C++?

**Answer:**
The `this` pointer is an implicit parameter to all non-static member functions. It points to the object for which the member function is called. It can be used to access members of the object within the member function.

Example:
```cpp
class MyClass {
public:
    int data;
    MyClass(int data) {
        this->data = data;
    }
    void show() {
        std::cout << "Data: " << this->data << std::endl;
    }
};

int main() {
    MyClass obj(10);
    obj.show();  // Outputs: Data: 10
    return 0;
}
```

### 7. What is a smart pointer and what are its types in C++?

**Answer:**
Smart pointers are objects that act as pointers but provide automatic memory management. They help in avoiding memory leaks by ensuring proper destruction of objects.

Types of smart pointers in C++:
- **std::unique_ptr:** Owns an object exclusively. Cannot be copied, only moved.
- **std::shared_ptr:** Allows multiple smart pointers to share ownership of an object. Uses reference counting to manage the object's lifetime.
- **std::weak_ptr:** A non-owning smart pointer that can be used to break reference cycles when using `std::shared_ptr`.

Example:
```cpp
#include <memory>

void example() {
    std::unique_ptr<int> uptr(new int(10));
    std::shared_ptr<int> sptr1(new int(20));
    std::shared_ptr<int> sptr2 = sptr1;  // Shared ownership
    std::weak_ptr<int> wptr = sptr1;     // Non-owning reference
}
```
### 8. What is the purpose of the `explicit` keyword in C++?

**Answer:**
The `explicit` keyword is used to prevent the compiler from using a constructor for implicit conversions. It is applied to constructors that can be called with a single argument. Without `explicit`, the compiler can use such a constructor for implicit conversions, which may lead to unexpected results.

Example:
```cpp
class MyClass {
public:
    explicit MyClass(int x) {
        // Constructor code
    }
};

int main() {
    MyClass obj1(10);  // OK
    MyClass obj2 = 10; // Error: conversion from 'int' to 'MyClass' is explicit
    return 0;
}
```

### 9. What is a lambda expression in C++11, and how is it used?

**Answer:**
A lambda expression in C++11 is a concise way to define an anonymous function object directly in the code. It is used for short snippets of code that are passed to algorithms or used as callbacks.

Example:
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::for_each(vec.begin(), vec.end(), [](int x) {
        std::cout << x << " ";
    });
    // Outputs: 1 2 3 4 5
    return 0;
}
```

### 10. What is the difference between `new` and `malloc`?

**Answer:**
- **`new`:** Allocates memory and calls the constructor to initialize the object. It returns a typed pointer.
- **`malloc`:** Allocates raw memory without calling any constructors. It returns a void pointer which needs to be cast to the appropriate type.

Example:
```cpp
class MyClass {
public:
    MyClass() {
        std::cout << "Constructor called" << std::endl;
    }
};

int main() {
    MyClass* obj1 = new MyClass();  // Calls constructor
    MyClass* obj2 = (MyClass*)malloc(sizeof(MyClass));  // Does not call constructor
    free(obj2);  // Must use free with malloc
    delete obj1; // Must use delete with new
    return 0;
}
```

### 11. What is the difference between `delete` and `delete[]`?

**Answer:**
- **`delete`:** Used to deallocate memory for a single object allocated with `new`.
- **`delete[]`:** Used to deallocate memory for an array of objects allocated with `new[]`.

Example:
```cpp
int main() {
    int* singleInt = new int(5);
    int* arrayInt = new int[5];
    delete singleInt;    // Correct
    delete[] arrayInt;   // Correct
    return 0;
}
```

### 12. What is the rule of three in C++?

**Answer:**
The rule of three states that if a class needs a user-defined destructor, copy constructor, or copy assignment operator, it likely needs all three. This is because such classes usually manage resources that need proper handling when copying or destroying objects.

Example:
```cpp
class MyClass {
private:
    int* data;
public:
    // Constructor
    MyClass(int value) : data(new int(value)) {}

    // Destructor
    ~MyClass() {
        delete data;
    }

    // Copy constructor
    MyClass(const MyClass& other) : data(new int(*other.data)) {}

    // Copy assignment operator
    MyClass& operator=(const MyClass& other) {
        if (this == &other) return *this;
        delete data;
        data = new int(*other.data);
        return *this;
    }
};
```

### 13. Explain move semantics and the rule of five in C++11.

**Answer:**
Move semantics improve performance by allowing the resources of temporary objects to be moved rather than copied. The rule of five extends the rule of three, adding move constructor and move assignment operator.

Example:
```cpp
class MyClass {
private:
    int* data;
public:
    // Constructor
    MyClass(int value) : data(new int(value)) {}

    // Destructor
    ~MyClass() {
        delete data;
    }

    // Copy constructor
    MyClass(const MyClass& other) : data(new int(*other.data)) {}

    // Copy assignment operator
    MyClass& operator=(const MyClass& other) {
        if (this == &other) return *this;
        delete data;
        data = new int(*other.data);
        return *this;
    }

    // Move constructor
    MyClass(MyClass&& other) noexcept : data(other.data) {
        other.data = nullptr;
    }

    // Move assignment operator
    MyClass& operator=(MyClass&& other) noexcept {
        if (this == &other) return *this;
        delete data;
        data = other.data;
        other.data = nullptr;
        return *this;
    }
};
```

### 14. What is a template in C++ and why is it used?

**Answer:**
Templates allow writing generic and reusable code. They enable functions and classes to operate with any data type without sacrificing performance.

Example:
```cpp
template <typename T>
T add(T a, T b) {
    return a + b;
}

int main() {
    std::cout << add<int>(1, 2) << std::endl;       // Outputs: 3
    std::cout << add<double>(1.1, 2.2) << std::endl; // Outputs: 3.3
    return 0;
}
```

### 15. What are the differences between `std::vector` and `std::array`?

**Answer:**
- **`std::vector`:** Dynamic array that can resize itself automatically when elements are added or removed. Memory is allocated on the heap.
- **`std::array`:** Fixed-size array, introduced in C++11. Memory is allocated on the stack, and the size must be known at compile-time.

Example:
```cpp
#include <vector>
#include <array>

int main() {
    std::vector<int> vec = {1, 2, 3};
    std::array<int, 3> arr = {4, 5, 6};

    vec.push_back(4);  // OK
    // arr.push_back(7); // Error: no member named 'push_back' in 'std::array<int, 3>'

    return 0;
}
```
### 16. What is the use of `const` keyword in C++?

**Answer:**
The `const` keyword can be used to declare:
- Constants.
- Function parameters as constant.
- Class member functions as constant.
- Pointers as constant.

Example:
```cpp
const int x = 10;            // Constant variable
void func(const int param);  // Constant parameter
class MyClass {
public:
    void display() const;    // Constant member function
};
const int* ptr;              // Constant pointer to int
```

### 17. Explain the concept of namespaces in C++.

**Answer:**
Namespaces are used to organize code into logical groups and to prevent name collisions that can occur especially when your code base includes multiple libraries.

Example:
```cpp
namespace MyNamespace {
    int value = 42;
}

int main() {
    std::cout << MyNamespace::value << std::endl;  // Accessing variable from namespace
    return 0;
}
```

### 18. What is the difference between `struct` and `class` in C++?

**Answer:**
The primary difference is the default access modifier:
- **struct:** Members are public by default.
- **class:** Members are private by default.

Example:
```cpp
struct MyStruct {
    int x;  // public by default
};

class MyClass {
    int x;  // private by default
};
```

### 19. What is a friend function in C++?

**Answer:**
A friend function is a function that is not a member of a class but has access to the class’s private and protected members. It is declared by using the keyword `friend`.

Example:
```cpp
class MyClass {
private:
    int x;
public:
    MyClass(int val) : x(val) {}
    friend void show(const MyClass& obj);
};

void show(const MyClass& obj) {
    std::cout << obj.x << std::endl;
}
```

### 20. Explain the concept of operator overloading in C++.

**Answer:**
Operator overloading allows you to redefine the way operators work for user-defined types (classes). This makes the code more intuitive and easier to read.

Example:
```cpp
class Complex {
public:
    int real, imag;
    Complex(int r = 0, int i = 0) : real(r), imag(i) {}

    // Overloading the + operator
    Complex operator + (const Complex& obj) {
        return Complex(real + obj.real, imag + obj.imag);
    }
};

int main() {
    Complex c1(1, 2), c2(3, 4);
    Complex c3 = c1 + c2;  // Using overloaded +
    return 0;
}
```

### 21. What are inline functions and when are they used?

**Answer:**
Inline functions are defined using the `inline` keyword and suggest to the compiler to insert the function’s body where the function call is made to avoid the overhead of a function call. They are typically used for small, frequently called functions.

Example:
```cpp
inline int add(int a, int b) {
    return a + b;
}
```

### 22. Explain the `mutable` keyword in C++.

**Answer:**
The `mutable` keyword allows a member of an object to be modified even if the object is declared as `const`. It is used in situations where some members of an object are allowed to change while others are not.

Example:
```cpp
class MyClass {
public:
    mutable int x;
    int y;

    MyClass() : x(0), y(0) {}
};

int main() {
    const MyClass obj;
    obj.x = 10;  // OK, x is mutable
    // obj.y = 20;  // Error, y is not mutable
    return 0;
}
```

### 23. What is the significance of the `volatile` keyword?

**Answer:**
The `volatile` keyword tells the compiler that a variable may be changed at any time by external factors and prevents the compiler from optimizing the variable. It is often used in embedded systems and multi-threaded applications.

Example:
```cpp
volatile int flag;
```

### 24. What is a copy constructor? Provide an example.

**Answer:**
A copy constructor is a special constructor in C++ used to create a new object as a copy of an existing object. It is defined as a constructor which takes a reference to an object of the same class as a parameter.

Example:
```cpp
class MyClass {
public:
    int* data;

    // Constructor
    MyClass(int val) : data(new int(val)) {}

    // Copy Constructor
    MyClass(const MyClass& other) : data(new int(*other.data)) {}

    // Destructor
    ~MyClass() {
        delete data;
    }
};

int main() {
    MyClass obj1(10);
    MyClass obj2 = obj1;  // Calls copy constructor
    return 0;
}
```

### 25. Explain what a move constructor is and provide an example.

**Answer:**
A move constructor is a special constructor in C++11 used to move resources from one object to another, rather than copying. This is more efficient for objects that manage large amounts of resources.

Example:
```cpp
class MyClass {
public:
    int* data;

    // Constructor
    MyClass(int val) : data(new int(val)) {}

    // Move Constructor
    MyClass(MyClass&& other) noexcept : data(other.data) {
        other.data = nullptr;
    }

    // Destructor
    ~MyClass() {
        delete data;
    }
};

int main() {
    MyClass obj1(10);
    MyClass obj2 = std::move(obj1);  // Calls move constructor
    return 0;
}
```

### 26. What are abstract classes in C++?

**Answer:**
Abstract classes are classes that cannot be instantiated and are designed to be inherited. They are declared using at least one pure virtual function.

Example:
```cpp
class AbstractClass {
public:
    virtual void show() = 0;  // Pure virtual function
};

class DerivedClass : public AbstractClass {
public:
    void show() override {
        std::cout << "Derived class implementation" << std::endl;
    }
};
```

### 27. What is a pure virtual function?

**Answer:**
A pure virtual function is a virtual function that must be overridden in a derived class. It is specified by assigning 0 to the function in the base class.

Example:
```cpp
class BaseClass {
public:
    virtual void display() = 0;  // Pure virtual function
};
```

### 28. Explain the concept of multiple inheritance in C++.

**Answer:**
Multiple inheritance is a feature in C++ where a class can inherit from more than one base class. This allows a derived class to inherit members from multiple base classes.

Example:
```cpp
class Base1 {
public:
    void show() {
        std::cout << "Base1" << std::endl;
    }
};

class Base2 {
public:
    void display() {
        std::cout << "Base2" << std::endl;
    }
};

class Derived : public Base1, public Base2 {};

int main() {
    Derived d;
    d.show();
    d.display();
    return 0;
}
```

### 29. What is the diamond problem in C++?

**Answer:**
The diamond problem occurs in multiple inheritance when two base classes have a common base class, and the derived class inherits from both base classes. This leads to ambiguity about which base class to inherit from.

Example:
```cpp
class A {
public:
    void show() {
        std::cout << "Class A" << std::endl;
    }
};

class B : public A {};
class C : public A {};
class D : public B, public C {};

int main() {
    D d;
    // d.show();  // Error: Ambiguity
    return 0;
}
```

### 30. How can the diamond problem be resolved in C++?

**Answer:**
The diamond problem can be resolved using virtual inheritance. This ensures that the base class is only inherited once, thus removing ambiguity.

Example:
```cpp
class A {
public:
    void show() {
        std::cout << "Class A" << std::endl;
    }
};

class B : virtual public A {};
class C : virtual public A {};
class D : public B, public C {};

int main() {
    D d;
    d.show();  // No ambiguity
    return 0;
}
```

### 31. What is polymorphism in C++?

**Answer:**
Polymorphism allows methods to do different things based on the object it is acting upon. It can be achieved using function overloading, operator overloading, and inheritance with virtual functions.

Example:
```cpp
class Base {
public:
    virtual void display() {
        std::cout << "Base class display" << std::endl;
    }
};

class Derived : public Base {
public:
    void display() override {
        std::cout << "Derived class display" << std::endl;
    }
};

int main() {
    Base* b = new Derived();
    b->display();  // Outputs: Derived class display
    delete b;
    return 0;
}
```

### 32. What is encapsulation in C++?

**Answer:**
Encapsulation is the bundling of data and methods that operate on the data into a

 single unit, typically a class. It also restricts direct access to some of the object's components, which is a means of preventing accidental interference and misuse of the methods and data.

Example:
```cpp
class MyClass {
private:
    int x;
public:
    void set(int a) {
        x = a;
    }
    int get() {
        return x;
    }
};
```

### 33. Explain the concept of inheritance in C++.

**Answer:**
Inheritance is a feature in C++ where a class (derived class) can inherit properties and behaviors (methods) from another class (base class). It promotes code reusability.

Example:
```cpp
class Base {
public:
    void display() {
        std::cout << "Base class display" << std::endl;
    }
};

class Derived : public Base {};

int main() {
    Derived d;
    d.display();  // Outputs: Base class display
    return 0;
}
```

### 34. What are virtual destructors and why are they needed?

**Answer:**
Virtual destructors ensure that the destructor of the derived class is called when an object is deleted through a base class pointer. This is essential to avoid resource leaks by ensuring proper cleanup of derived class objects.

Example:
```cpp
class Base {
public:
    virtual ~Base() {
        std::cout << "Base Destructor" << std::endl;
    }
};

class Derived : public Base {
public:
    ~Derived() {
        std::cout << "Derived Destructor" << std::endl;
    }
};

int main() {
    Base* b = new Derived();
    delete b;  // Calls Derived Destructor followed by Base Destructor
    return 0;
}
```

### 35. What is the difference between `override` and `final` specifiers in C++11?

**Answer:**
- **`override`:** Ensures that the function is overriding a virtual function in the base class. It produces a compile-time error if no such virtual function exists.
- **`final`:** Prevents a class from being inherited from or a virtual function from being overridden.

Example:
```cpp
class Base {
public:
    virtual void display() {}
};

class Derived : public Base {
public:
    void display() override {}  // Correct use of override
    // void display(int) override {}  // Error: No virtual function to override
};

class FinalClass final {};

class DerivedFromFinal : public FinalClass {};  // Error: Cannot inherit from final class

class AnotherDerived : public Base {
public:
    void display() final {}  // Prevent further overriding
};

class FurtherDerived : public AnotherDerived {
public:
    void display() {}  // Error: display() is final in AnotherDerived
};
```

### 36. What are function pointers and how are they used?

**Answer:**
Function pointers are pointers that point to the address of a function. They can be used to call functions and can be passed as arguments to other functions.

Example:
```cpp
#include <iostream>

void func(int x) {
    std::cout << "Value: " << x << std::endl;
}

int main() {
    void (*funcPtr)(int) = func;  // Function pointer
    funcPtr(10);  // Calls func with argument 10
    return 0;
}
```

### 37. Explain the concept of templates in C++.

**Answer:**
Templates allow writing generic and reusable code. They enable functions and classes to operate with any data type without sacrificing performance. Templates can be function templates or class templates.

Example:
```cpp
template <typename T>
T add(T a, T b) {
    return a + b;
}

int main() {
    std::cout << add<int>(1, 2) << std::endl;       // Outputs: 3
    std::cout << add<double>(1.1, 2.2) << std::endl; // Outputs: 3.3
    return 0;
}
```

### 38. What is the Standard Template Library (STL) in C++?

**Answer:**
The STL is a powerful set of C++ template classes to provide general-purpose classes and functions with templates that implement many popular and commonly used algorithms and data structures like vectors, lists, queues, and stacks.

### 39. What are the main components of STL?

**Answer:**
The main components of STL are:
- **Containers:** Data structures like `vector`, `list`, `deque`, `set`, `map`, etc.
- **Algorithms:** Functions for sorting, searching, manipulating, etc.
- **Iterators:** Objects that point to elements within containers and are used to traverse containers.

### 40. Explain the use of `std::vector`.

**Answer:**
`std::vector` is a sequence container that encapsulates dynamic size arrays. It provides fast random access, can grow and shrink dynamically, and provides several member functions to manipulate the elements.

Example:
```cpp
#include <vector>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    vec.push_back(6);  // Add element to end
    vec.pop_back();    // Remove element from end
    for (int x : vec) {
        std::cout << x << " ";
    }
    return 0;
}
```

### 41. How do you sort a `std::vector`?

**Answer:**
You can sort a `std::vector` using the `std::sort` algorithm provided by the STL.

Example:
```cpp
#include <vector>
#include <algorithm>
#include <iostream>

int main() {
    std::vector<int> vec = {5, 3, 2, 4, 1};
    std::sort(vec.begin(), vec.end());
    for (int x : vec) {
        std::cout << x << " ";  // Outputs: 1 2 3 4 5
    }
    return 0;
}
```

### 42. Explain the use of `std::map`.

**Answer:**
`std::map` is an associative container that stores key-value pairs, where each key is unique. It provides fast retrieval based on keys.

Example:
```cpp
#include <map>
#include <iostream>

int main() {
    std::map<int, std::string> myMap;
    myMap[1] = "one";
    myMap[2] = "two";
    myMap[3] = "three";

    for (const auto& pair : myMap) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
    return 0;
}
```

### 43. What is the difference between `std::map` and `std::unordered_map`?

**Answer:**
- **`std::map`:** Stores elements in a balanced tree structure, allowing elements to be sorted by keys. Provides logarithmic time complexity for insert and search operations.
- **`std::unordered_map`:** Stores elements in a hash table, allowing faster average time complexity for insert and search operations (constant time), but does not maintain any order of elements.

### 44. Explain the use of `std::set`.

**Answer:**
`std::set` is an associative container that stores unique elements following a specific order. It provides fast retrieval based on keys and does not allow duplicate elements.

Example:
```cpp
#include <set>
#include <iostream>

int main() {
    std::set<int> mySet = {5, 3, 2, 4, 1};
    mySet.insert(6);
    mySet.erase(3);
    for (int x : mySet) {
        std::cout << x << " ";  // Outputs: 1 2 4 5 6
    }
    return 0;
}
```

### 45. What is the difference between `std::set` and `std::multiset`?

**Answer:**
- **`std::set`:** Does not allow duplicate elements.
- **`std::multiset`:** Allows duplicate elements and stores them in a specific order.

### 46. Explain the use of `std::list`.

**Answer:**
`std::list` is a sequence container that allows non-contiguous memory allocation. It provides fast insertion and deletion of elements anywhere in the sequence, but slow random access.

Example:
```cpp
#include <list>
#include <iostream>

int main() {
    std::list<int> myList = {1, 2, 3, 4, 5};
    myList.push_back(6);  // Add element to end
    myList.push_front(0); // Add element to front
    myList.pop_back();    // Remove element from end
    myList.pop_front();   // Remove element from front
    for (int x : myList) {
        std::cout << x << " ";  // Outputs: 1 2 3 4 5
    }
    return 0;
}
```

### 47. What are iterators in C++?

**Answer:**
Iterators are objects that point to elements within containers and are used to traverse through the elements of the container. They provide a uniform interface to iterate over different types of containers.

Example:
```cpp
#include <vector>
#include <iostream>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";  // Outputs: 1 2 3 4 5
    }
    return

 0;
}
```

### 48. What is a smart pointer and how is it different from a regular pointer?

**Answer:**
Smart pointers are objects that manage the lifetime of dynamically allocated memory. They automatically deallocate memory when it is no longer needed, reducing the risk of memory leaks. Unlike regular pointers, smart pointers provide automatic memory management.

Types of smart pointers:
- **`std::unique_ptr`:** Manages sole ownership of a resource.
- **`std::shared_ptr`:** Manages shared ownership of a resource.
- **`std::weak_ptr`:** Non-owning reference to a `std::shared_ptr`.

Example:
```cpp
#include <memory>
#include <iostream>

int main() {
    std::unique_ptr<int> ptr1 = std::make_unique<int>(10);
    std::cout << *ptr1 << std::endl;  // Outputs: 10

    std::shared_ptr<int> ptr2 = std::make_shared<int>(20);
    std::shared_ptr<int> ptr3 = ptr2;
    std::cout << *ptr3 << std::endl;  // Outputs: 20

    std::weak_ptr<int> weakPtr = ptr2;
    std::cout << weakPtr.use_count() << std::endl;  // Outputs: 2

    return 0;
}
```

### 49. What is RAII (Resource Acquisition Is Initialization) in C++?

**Answer:**
RAII is a programming idiom in C++ where resources are tied to the lifetime of objects. Resources are acquired during object creation and released during object destruction, ensuring resource management is exception-safe.

Example:
```cpp
class FileHandle {
private:
    FILE* file;
public:
    FileHandle(const char* filename) {
        file = fopen(filename, "r");
    }
    ~FileHandle() {
        if (file) {
            fclose(file);
        }
    }
};

int main() {
    FileHandle fh("example.txt");
    return 0;
}
```

### 50. Explain the concept of exception handling in C++.

**Answer:**
Exception handling in C++ allows a program to handle runtime errors gracefully. It uses the `try`, `catch`, and `throw` keywords. Code that may throw an exception is placed inside a `try` block, and exceptions are caught and handled in `catch` blocks.

Example:
```cpp
#include <iostream>

int main() {
    try {
        throw std::runtime_error("An error occurred");
    } catch (const std::runtime_error& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    return 0;
}
```

### 51. What are the rules for exception specification in C++?

**Answer:**
C++11 introduced the `noexcept` specifier to indicate whether a function can throw exceptions. Functions declared `noexcept` are guaranteed not to throw exceptions.

Example:
```cpp
void func1() noexcept {
    // No exceptions will be thrown from here
}

void func2() noexcept(false) {
    // Exceptions might be thrown from here
}
```

### 52. What is a lambda expression in C++11?

**Answer:**
Lambda expressions are anonymous functions that can be defined in-line. They can capture variables from the surrounding scope and can be used to write short, concise function objects.

Example:
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    std::for_each(vec.begin(), vec.end(), [](int x) {
        std::cout << x << " ";  // Outputs: 1 2 3 4 5
    });
    return 0;
}
```

### 53. What are variadic templates?

**Answer:**
Variadic templates allow functions and classes to accept a variable number of arguments. They use template parameter packs and recursion to handle each argument.

Example:
```cpp
#include <iostream>

template<typename T>
void print(T t) {
    std::cout << t << std::endl;
}

template<typename T, typename... Args>
void print(T t, Args... args) {
    std::cout << t << " ";
    print(args...);
}

int main() {
    print(1, 2.5, "Hello");
    return 0;
}
```

### 54. What are constexpr functions?

**Answer:**
`constexpr` functions are evaluated at compile-time if all their arguments are compile-time constants. They help in performing constant expressions and can be used in constant expressions.

Example:
```cpp
constexpr int add(int a, int b) {
    return a + b;
}

int main() {
    constexpr int result = add(1, 2);
    std::cout << result << std::endl;  // Outputs: 3
    return 0;
}
```

### 55. What is a nullptr in C++11?

**Answer:**
`nullptr` is a keyword representing a null pointer constant. It is type-safe and can be used in place of `NULL` or `0` to represent null pointers.

Example:
```cpp
void func(int* ptr) {
    if (ptr == nullptr) {
        std::cout << "Null pointer" << std::endl;
    }
}

int main() {
    int* p = nullptr;
    func(p);
    return 0;
}
```

### 56. What is a unique pointer in C++11?

**Answer:**
`std::unique_ptr` is a smart pointer that owns and manages another object through a pointer and disposes of that object when the `std::unique_ptr` goes out of scope. It ensures single ownership.

Example:
```cpp
#include <memory>
#include <iostream>

int main() {
    std::unique_ptr<int> ptr = std::make_unique<int>(10);
    std::cout << *ptr << std::endl;  // Outputs: 10
    return 0;
}
```

### 57. What is a shared pointer in C++11?

**Answer:**
`std::shared_ptr` is a smart pointer that retains shared ownership of an object through a pointer. Multiple `std::shared_ptr` instances can manage the same object, and the object is destroyed when the last `std::shared_ptr` managing it is destroyed.

Example:
```cpp
#include <memory>
#include <iostream>

int main() {
    std::shared_ptr<int> ptr1 = std::make_shared<int>(20);
    std::shared_ptr<int> ptr2 = ptr1;
    std::cout << *ptr2 << std::endl;  // Outputs: 20
    return 0;
}
```

### 58. What is a weak pointer in C++11?

**Answer:**
`std::weak_ptr` is a smart pointer that holds a non-owning reference to an object managed by `std::shared_ptr`. It is used to break circular references in a graph of shared pointers.

Example:
```cpp
#include <memory>
#include <iostream>

class MyClass {
public:
    std::shared_ptr<MyClass> ptr;
};

int main() {
    auto obj1 = std::make_shared<MyClass>();
    auto obj2 = std::make_shared<MyClass>();
    obj1->ptr = obj2;
    obj2->ptr = obj1;  // Circular reference
    return 0;
}
```

### 59. What is type inference with `auto` in C++11?

**Answer:**
`auto` allows the compiler to automatically deduce the type of a variable from its initializer. It helps in reducing code verbosity and improving readability.

Example:
```cpp
#include <iostream>

int main() {
    auto x = 10;          // int
    auto y = 10.5;        // double
    auto z = "Hello";     // const char*
    std::cout << x << " " << y << " " << z << std::endl;
    return 0;
}
```

### 60. What is range-based for loop in C++11?

**Answer:**
Range-based for loop allows iterating over all elements in a container or array in a more readable and concise manner.

Example:
```cpp
#include <vector>
#include <iostream>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    for (int x : vec) {
        std::cout << x << " ";  // Outputs: 1 2 3 4 5
    }
    return 0;
}
```

### 61. What are user-defined literals in C++11?

**Answer:**
User-defined literals allow the creation of custom literals that extend the language's built-in literals. They can be used to define new suffixes for literals.

Example:
```cpp
#include <iostream>

constexpr long double operator"" _km(long double x) {
    return x * 1000;
}

int main() {
    std::cout << 5.0_km << " meters" << std::endl;  // Outputs: 5000 meters
    return 0;
}
```

### 62. Explain the `decltype` keyword in C++11.

**Answer:**
`decltype` inspects the declared type of an expression. It can be used to declare variables with the same type as another expression without explicitly specifying the type.

Example:
```cpp
#include <iostream>

int main() {
    int a = 10;
    decltype(a) b = 20;  // b is of type int
    std::cout << b << std::endl;  // Outputs:

 20
    return 0;
}
```

### 63. What is a delegating constructor in C++11?

**Answer:**
A delegating constructor is a constructor that delegates all or part of its initialization to another constructor in the same class.

Example:
```cpp
#include <iostream>

class MyClass {
public:
    MyClass() : MyClass(0) {
        std::cout << "Default constructor" << std::endl;
    }
    MyClass(int x) {
        std::cout << "Parameterized constructor with x = " << x << std::endl;
    }
};

int main() {
    MyClass obj;
    return 0;
}
```

### 64. What is an explicit conversion operator in C++11?

**Answer:**
An explicit conversion operator is used to define explicit type conversion functions. It prevents implicit conversions and requires explicit casting.

Example:
```cpp
#include <iostream>

class MyClass {
    int x;
public:
    explicit MyClass(int a) : x(a) {}
    explicit operator int() const {
        return x;
    }
};

int main() {
    MyClass obj(10);
    int x = static_cast<int>(obj);  // Explicit conversion
    std::cout << x << std::endl;  // Outputs: 10
    return 0;
}
```

### 65. Explain the concept of rvalue references and move semantics in C++11.

**Answer:**
Rvalue references are used to distinguish between lvalues and rvalues. They enable move semantics, which allows resources to be moved instead of copied, improving performance by eliminating unnecessary copying.

Example:
```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> v1 = {1, 2, 3};
    std::vector<int> v2 = std::move(v1);  // v1's resources are moved to v2
    std::cout << "v1 size: " << v1.size() << std::endl;  // Outputs: 0
    std::cout << "v2 size: " << v2.size() << std::endl;  // Outputs: 3
    return 0;
}
```

### 66. What is a trailing return type in C++11?

**Answer:**
A trailing return type allows specifying the return type of a function after the parameter list, which is useful for complex return types or when the return type depends on the parameters.

Example:
```cpp
#include <iostream>

auto add(int a, int b) -> int {
    return a + b;
}

int main() {
    std::cout << add(1, 2) << std::endl;  // Outputs: 3
    return 0;
}
```

### 67. What are initializer lists in C++11?

**Answer:**
Initializer lists allow a class to be initialized with a list of values. They enable uniform initialization syntax and can be used with `std::initializer_list`.

Example:
```cpp
#include <vector>
#include <iostream>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    for (int x : vec) {
        std::cout << x << " ";  // Outputs: 1 2 3 4 5
    }
    return 0;
}
```

### 68. What is `std::thread` in C++11?

**Answer:**
`std::thread` is a class that represents a single thread of execution. It allows the creation and management of threads in a C++ program.

Example:
```cpp
#include <thread>
#include <iostream>

void func() {
    std::cout << "Thread function" << std::endl;
}

int main() {
    std::thread t(func);
    t.join();  // Wait for thread to finish
    return 0;
}
```

### 69. What is `std::mutex` in C++11?

**Answer:**
`std::mutex` is a synchronization primitive used to protect shared data from being simultaneously accessed by multiple threads. It ensures that only one thread accesses the critical section at a time.

Example:
```cpp
#include <mutex>
#include <thread>
#include <iostream>

std::mutex mtx;

void print(int x) {
    std::lock_guard<std::mutex> lock(mtx);
    std::cout << "Value: " << x << std::endl;
}

int main() {
    std::thread t1(print, 1);
    std::thread t2(print, 2);
    t1.join();
    t2.join();
    return 0;
}
```

### 70. What are `std::lock_guard` and `std::unique_lock` in C++11?

**Answer:**
- **`std::lock_guard`:** A RAII-style mechanism that acquires a mutex when created and releases it when destroyed.
- **`std::unique_lock`:** A more flexible lock that can be used for deferred locking, timed locking, and unlocking before destruction.

Example:
```cpp
#include <mutex>
#include <thread>
#include <iostream>

std::mutex mtx;

void print(int x) {
    std::lock_guard<std::mutex> lock(mtx);
    std::cout << "Value: " << x << std::endl;
}

void print_deferred(int x) {
    std::unique_lock<std::mutex> lock(mtx, std::defer_lock);
    lock.lock();
    std::cout << "Deferred Value: " << x << std::endl;
    lock.unlock();
}

int main() {
    std::thread t1(print, 1);
    std::thread t2(print_deferred, 2);
    t1.join();
    t2.join();
    return 0;
}
```

### 71. Explain the concept of futures and promises in C++11.

**Answer:**
Futures and promises are synchronization primitives used for asynchronous operations. A `promise` is an object that can store a value to be retrieved by a `future`. A `future` is an object that can retrieve the value set by a promise.

Example:
```cpp
#include <future>
#include <iostream>

void func(std::promise<int>& p) {
    p.set_value(10);  // Set value to be retrieved by future
}

int main() {
    std::promise<int> p;
    std::future<int> f = p.get_future();
    std::thread t(func, std::ref(p));
    std::cout << f.get() << std::endl;  // Outputs: 10
    t.join();
    return 0;
}
```

### 72. What is `std::async` in C++11?

**Answer:**
`std::async` is a function template that runs a function asynchronously (potentially in a separate thread) and returns a `std::future` to retrieve the result.

Example:
```cpp
#include <future>
#include <iostream>

int func() {
    return 10;
}

int main() {
    std::future<int> result = std::async(func);
    std::cout << result.get() << std::endl;  // Outputs: 10
    return 0;
}
```

### 73. Explain the concept of atomic operations in C++11.

**Answer:**
Atomic operations are operations that are performed without interruption. They are used to prevent data races in multi-threaded programs. The `std::atomic` template provides atomic operations for various data types.

Example:
```cpp
#include <atomic>
#include <thread>
#include <iostream>

std::atomic<int> counter(0);

void increment() {
    for (int i = 0; i < 1000; ++i) {
        counter++;
    }
}

int main() {
    std::thread t1(increment);
    std::thread t2(increment);
    t1.join();
    t2.join();
    std::cout << counter << std::endl;  // Outputs: 2000
    return 0;
}
```

### 74. What is `std::chrono` in C++11?

**Answer:**
`std::chrono` is a library for dealing with time-related functionality, such as measuring time intervals, handling durations, and dealing with clocks and time points.

Example:
```cpp
#include <chrono>
#include <thread>
#include <iostream>

int main() {
    auto start = std::chrono::high_resolution_clock::now();
    std::this_thread::sleep_for(std::chrono::seconds(1));  // Sleep for 1 second
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Elapsed time: " << elapsed.count() << " seconds" << std::endl;
    return 0;
}
```

### 75. What are alignas and alignof in C++11?

**Answer:**
- **`alignas`:** Specifies the alignment of a type or a variable.
- **`alignof`:** Returns the alignment requirement of a type.

Example:
```cpp
#include <iostream>

struct alignas(16) MyStruct {
    int x;
};

int main() {
    std::cout << alignof(MyStruct) << std::endl;  // Outputs: 16
    return 0;
}
```

### 76. What is `noexcept` in C++11?

**Answer:**
`noexcept` specifies that a function does not throw exceptions. It helps in optimization and provides stronger exception safety guarantees.

Example:
```cpp
void func() noexcept {
    // Function that does not throw exceptions
}

int main() {
    func();
    return 

0;
}
```

### Data Structures and Algorithms (DSA) Overview: Key Concepts

1. **Graphs:**
   - **Definition:** A graph is a collection of nodes (vertices) and edges connecting pairs of nodes. Graphs can be directed (where edges have a direction) or undirected.
   - **Types:**
     - **Directed Graph (Digraph):** Edges have a direction (e.g., web pages with hyperlinks).
     - **Undirected Graph:** Edges have no direction (e.g., social networks).
     - **Weighted Graph:** Edges have weights or costs associated with them (e.g., road networks).
   - **Representations:**
     - **Adjacency Matrix:** A 2D array where the element at row `i` and column `j` is `1` (or the weight) if there is an edge between vertex `i` and vertex `j`.
     - **Adjacency List:** An array of lists, where each list contains the neighbors of a vertex.
   - **Algorithms:**
     - **Breadth-First Search (BFS):** Explores nodes level by level, useful for finding the shortest path in unweighted graphs.
     - **Depth-First Search (DFS):** Explores as far as possible along each branch before backtracking, useful for detecting cycles.
     - **Dijkstra's Algorithm:** Finds the shortest path in weighted graphs.
     - **Kruskal’s and Prim’s Algorithms:** Used for finding the Minimum Spanning Tree (MST).

2. **Heap:**
   - **Definition:** A heap is a special tree-based data structure that satisfies the heap property. It's commonly used to implement priority queues.
   - **Types:**
     - **Min-Heap:** The value of the parent node is less than or equal to the values of its children. The root is the minimum element.
     - **Max-Heap:** The value of the parent node is greater than or equal to the values of its children. The root is the maximum element.
   - **Operations:**
     - **Insertion:** Add a new element at the end of the heap and then "bubble up" to restore the heap property.
     - **Deletion:** Typically, the root is removed. The last element replaces the root, and then "bubble down" to restore the heap property.
     - **Peek:** Retrieve the root element without removing it (min or max element).
     - **Heapify:** Converts an arbitrary array into a heap.
   - **Applications:**
     - **Priority Queue:** Efficiently access the highest (or lowest) priority element.
     - **Heap Sort:** An efficient comparison-based sorting algorithm.

3. **Dynamic Programming (DP):**
   - **Definition:** DP is an optimization technique used to solve problems by breaking them down into simpler subproblems, storing the results of subproblems to avoid redundant work.
   - **Key Concepts:**
     - **Overlapping Subproblems:** The problem can be broken down into smaller, repeated subproblems.
     - **Optimal Substructure:** The optimal solution to the problem can be constructed from optimal solutions of its subproblems.
     - **Memoization:** Storing the results of expensive function calls and reusing them when the same inputs occur again.
     - **Tabulation:** Iteratively solving subproblems and storing their results in a table.
   - **Common Problems:**
     - **Fibonacci Sequence:** Calculate the nth Fibonacci number efficiently.
     - **Knapsack Problem:** Maximize the total value in the knapsack without exceeding its weight capacity.
     - **Longest Common Subsequence (LCS):** Find the longest subsequence present in two sequences.
     - **Coin Change Problem:** Determine the minimum number of coins needed to make a specific amount.

4. **Map and Tries:**
   - **Map (HashMap/Dictionary):**
     - **Definition:** A map is a collection of key-value pairs, where each key is unique. Hash maps provide fast access to values based on keys.
     - **Operations:**
       - **Insertion:** Insert a key-value pair.
       - **Deletion:** Remove a key-value pair.
       - **Lookup:** Retrieve the value associated with a given key.
     - **Applications:** Used for associative arrays, counting occurrences, and indexing.
     - **Common Implementations:** Hash tables, balanced binary search trees (like Red-Black trees in C++).
   
   - **Trie (Prefix Tree):**
     - **Definition:** A trie is a tree-like data structure that stores a dynamic set of strings, where keys are usually strings. Each node represents a common prefix of some strings.
     - **Operations:**
       - **Insertion:** Add a word to the trie by creating a path from the root to a terminal node representing the word.
       - **Search:** Check if a word or prefix exists in the trie.
       - **Deletion:** Remove a word from the trie.
     - **Applications:**
       - **Auto-Complete:** Suggest possible words based on a prefix.
       - **Spell Checking:** Quickly look up words.
       - **IP Routing:** Efficiently match prefixes of IP addresses.
     - **Advantages:** Tries can be faster than hash maps for prefix-related queries and can provide lexicographic ordering.

These concepts are fundamental in various algorithms and data structures and are essential for solving complex computational problems efficiently.
