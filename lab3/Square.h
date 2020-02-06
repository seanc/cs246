#ifndef SQUARE_H
#define SQUARE_H

#include <iostream>
#include <sstream>

class Square {
  private:
    double side;
  
  public:
    Square() : side(1) {};

    Square(double side) {
      this->side = side > 0 ? side : 1;
    }

    Square(const Square& obj) {
      side = obj.side > 0 ? obj.side : 1;
    }

    Square& operator=(const Square& rhs) {
      if (this != &rhs) {
        side = rhs.side > 0 ? rhs.side : 1;
      }

      return *this;
    }

    ~Square() {}

    double GetSide() const {
      return side;
    }

    double SetSide(int side) {
      if (side > 0) this->side = side;
    }

    double GetPerimeter() {
      return 4 * side;
    }

    double Area() {
      return side * side;
    }

    std::string ToString() const {
      std::stringstream out;

      out << '(' << side << ')';

      return out.str();
    }

    friend std::ostream& operator<<(std::ostream& out, const Square& obj) {
      out << obj.ToString();
      return out;
    }
};
#endif