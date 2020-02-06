#include <iostream>
#include "Square.h"

void printSquare(std::string name, Square s) {
  std::cout << std::endl << "Square " << name << " | Side : " << s.GetSide() <<" | Perimeter : " << s.GetPerimeter() << " | Area: " << s.Area() << std::endl; 
}

int main () {
  Square s1, s2(4), s3(-6), s4(9);

  printSquare("s1", s1);
  printSquare("s2", s2);
  printSquare("s3", s3);
  printSquare("s4", s4);

  std::cout << "Copy constructor s1 = s2" << std::endl;
  s1 = s2;

  printSquare("s1", s1);
  printSquare("s2", s2);
  printSquare("s3", s3);
  printSquare("s4", s4);

  std::cout << "Overloaded assignment operator s2 = s1" << std::endl;
  s2 = s1;

  printSquare("s1", s1);
  printSquare("s2", s2);
  printSquare("s3", s3);
  printSquare("s4", s4);

  std::cout << "Set Side s3.SetSide(100)";
  s3.SetSide(100);

  printSquare("s1", s1);
  printSquare("s2", s2);
  printSquare("s3", s3);
  printSquare("s4", s4);

  std::cout << "Override inputted side if not positive s4.SetSide(-100)";
  s4.SetSide(-100);

  printSquare("s1", s1);
  printSquare("s2", s2);
  printSquare("s3", s3);
  printSquare("s4", s4);
}