#ifndef SHAPE_H
#define SHAPE_H

class Shape {
  private:
    Shape();
  public:
    virtual double Perimeter () const {}
    virtual double Area() const {}
    
};

#endif