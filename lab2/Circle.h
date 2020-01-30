#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

static const double PI = 3.141592;

class Circle {
    private:
        double radius;
    
    public:
        // Default constructor
        Circle() : radius(1) {}

        // Overloaded constructor
        Circle(double radius) : Circle() {
            if (radius < 0) {
                this->radius = 1;
            } else {
                this->radius = radius;
            }
        }
        
        // Copy constructor
        Circle(const Circle& obj) {
            radius = obj.radius;
        }

        // Overloaded assignment operator
        Circle& operator=(const Circle& circle) {
            if (this != &circle) {
                this->radius = circle.radius;
            }

            return *this;
        }

        // Destructor
        ~Circle() {}

        int GetRadius() {
            return radius;
        }

        int GetRadius() const {
            return radius;
        }

        void SetRadius(double radius) {
            if (radius < 0) {
                throw "Radius must be non-negative";
            } else {
                this->radius = radius;
            }
        }

        double Diameter() const {
             return this->radius * 2;
        }
        
        double Circumference() const {
            return 2 * PI * this->radius; 
        }

        double Area() const {
            return PI * (this->radius * this->radius);
        }

        std::string ToString() const {
            std::stringstream out;
            out << std::setprecision(2) << radius;
            return out.str();
        }

        friend std::ostream& operator<<(std::ostream& out, const Circle& obj) {
            out << obj.ToString();
            return out;
        }
};

#endif