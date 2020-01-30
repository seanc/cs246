#include <iostream>
#include <sstream>
#include "Circle.h"

void printDetails (std::string name, Circle c) {
    std::stringstream details;

    details << name;
    details << " | Radius: " << c;
    details << " | Diameter: " << c.Diameter();
    details << " | Circumference: " << c.Circumference();
    details << " | Area: " << c.Area();
    details << std::endl; 

    std::cout << details.str();
}

int main() {
    Circle a, b(2), c(3.877639924123), d;
    a = b;
    d = c;

    printDetails("A", a);
    printDetails("B", b);
    printDetails("C", c);
    printDetails("D", d);

    c.SetRadius(5);

    printDetails("C", c);

    try {
        std::cout << "Changing radius to negative:" << std::endl;
        a.SetRadius(-15);
    } catch (const char *error) {
        std::cout << "Error: " << error << std::endl;
    }

    return 0;
}