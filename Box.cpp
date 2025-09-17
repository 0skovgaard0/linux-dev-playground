#include <iostream>
#include <string>

class Box {
public:
    Box() : xHeight(0), yWidth(0), str("") {   // Default constructor
        std::cout << "Default constructor is called!" << std::endl;
    }

    Box(int xHeight, int yWidth) : xHeight(xHeight), yWidth(yWidth) {
        std::cout << "Parameterized constructor called!" << std::endl;
    }

    Box(const std::string& str, int x = 0, int y = 0) 
        : str(str), xHeight(x), yWidth(y) {
        std::cout << "String constructor called!" << std::endl;
    }

    // Copy constructor
    Box(const Box& other) 
        : xHeight(other.xHeight), yWidth(other.yWidth), str(other.str) {
        std::cout << "Copy constructor called!" << std::endl;
    }

    // Move constructor
    Box(Box&& other) noexcept 
        : xHeight(other.xHeight), yWidth(other.yWidth), str(std::move(other.str)) {
        std::cout << "Move constructor called!" << std::endl;
        other.xHeight = 0;
        other.yWidth = 0;
    }

    // Copy assignment
    Box& operator=(const Box& other) {
        std::cout << "Copy assignment called!" << std::endl;
        if (this != &other) {
            xHeight = other.xHeight;
            yWidth = other.yWidth;
            str = other.str;
        }
        return *this;
    }

    // Move assignment
    Box& operator=(Box&& other) noexcept {
        std::cout << "Move assignment called!" << std::endl;
        if (this != &other) {
            xHeight = other.xHeight;
            yWidth = other.yWidth;
            str = std::move(other.str);
            other.xHeight = 0;
            other.yWidth = 0;
        }
        return *this;
    }

    int area() const {
        return xHeight * yWidth;
    }

    friend std::ostream& operator<<(std::ostream& os, const Box& box) {
        os << "Box(str=\"" << box.str << "\", area=" << box.area() << ")";
        return os;
    }

    ~Box() {
        std::cout << "Box destructor called !!" << std::endl;
    }

private:
    int xHeight;
    int yWidth;
    std::string str;
};

int main() {
    Box b1;                     // Default constructor
    Box b2(26, 2);              // Parameterized constructor
    Box b5("I love handling memory efficiency!");  // String constructor

    Box b3 = b2;                // Copy constructor
    Box b4 = b5;                // Copy constructor

    std::cout << "b2's area = " << b2.area() << std::endl;
    std::cout << "b3's area = " << b3.area() << std::endl;

    std::cout << "b5 = " << b5 << std::endl;
    std::cout << "b4 = " << b4 << std::endl;

    std::cout << "---- std::move demo ----" << std::endl;
    Box b6 = std::move(b5);     // Move constructor
    std::cout << "b6 = " << b6 << std::endl;
    std::cout << "b5 = " << b5 << std::endl; // b5 has been "moved-from"

    b4 = std::move(b2);         // Move assignment
    std::cout << "b4 = " << b4 << std::endl;
    std::cout << "b2 = " << b2 << std::endl; // b2 moved-from

    return 0;
}
