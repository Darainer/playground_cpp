//
// Created by ryan on 29.02.20.
//
#ifndef PLAYGROUND_OBJECT_HPP
#define PLAYGROUND_OBJECT_HPP
#include <array>
#endif // PLAYGROUND_OBJECT_HPP

#include "templates.h"
#include <cmath>
#include <iostream>
#include <vector>

namespace Object_types {

enum class ObjectType { Undefined = 0, Vehicle = 1, Pedestrian = 2, Bicycle = 3 };  //more typesafe than plain enum 

class Point {
public:
  double position_x;
  double position_y;
  Point() : Point(0, 255) {} // default constructor

  Point(double pos_x, double pos_y) {
    position_x = pos_x;
    position_y = pos_y;
  }
  Point(const Point &p) // copy constructor
      : position_x{p.position_x}, position_y{p.position_y} {}


friend bool const operator<(const Point &lhs, const Point &rhs)  {       // friends are allowed in A11-3-1 for comparison operations
    return lhs.distance_to_origin() < rhs.distance_to_origin();
  }

friend bool const operator>(const Point &lhs, const Point &rhs)  {      // friends are allowed in A11-3-1 for comparison operations
    return lhs.distance_to_origin() > rhs.distance_to_origin();
  }

private:
  double distance_to_origin() const {
    return std::sqrt(position_x * position_x + position_y * position_y);
  }
};

class BoundingBox {
public:
  Point top_left;
  Point top_right;
  Point bottom_left;
  Point bottom_right;

  BoundingBox() : BoundingBox(Point(), Point(), Point(), Point()) {}

  BoundingBox(Point t_l, Point t_r, Point b_l, Point b_r) {
    top_left = t_l;
    top_right = t_r;
    bottom_left = b_l;
    bottom_right = {b_r};
  }
  BoundingBox(std::vector<Point> points) {
    if (points.size() == 4) {
      top_left = points.at(0);
      top_right = points.at(1);
      bottom_left = points.at(2);
      bottom_right = points.at(3);
    } else {
      throw;
    };
  }
  double calculate_rear_width() {
    double width = bottom_right.position_x - bottom_left.position_x;
    return width;
  };
  double calculate_area_if_square() {
    double width = bottom_right.position_x - bottom_left.position_x;
    double length = top_left.position_x - bottom_right.position_x;
    return width * length;
  }
  friend bool operator<(BoundingBox &lhs, BoundingBox &rhs) {
    return lhs.bottom_right < rhs.bottom_right;
  }
  const Point &return_closest_point() {
    int a = std::min(1, 4);
    const Point &myPoint =
        ryan_stl::my_max4(bottom_left, bottom_right, top_right, top_left);
    return myPoint;
  }
};

class Object {
private:
  BoundingBox m_BoundingBox{};
  double m_width{};
  ObjectType objectType;
  int m_ID;

public:
  static int objectCount;
  static void init_object() { objectCount = 0; }
  static int getCount() { return objectCount; }
  Object() {
    m_BoundingBox = BoundingBox();
    objectCount++;
    m_ID = getCount();
    objectType = ObjectType::Vehicle;
    calculateObjectWidth();
  };
  // Constructor definition
  Object(BoundingBox &BBox, ObjectType &Type) {
    std::cout << "Constructor called." << std::endl;
    m_BoundingBox = BBox;
    objectType = Type;
    calculateObjectWidth();
    // Increase every time object is created
    objectCount++;
  }
  Object(const Object &copied_object) {
    m_BoundingBox = copied_object.get_BoundingBox();
    objectType = copied_object.get_Type();
    calculateObjectWidth();
    std::cout << "copy constructor called." << std::endl;
    objectCount++;
  }
  ~Object() {
    std::cout << "destructor called" << std::endl;
    objectCount--;
    std::cout << "object count = " << objectCount << std::endl;
  }

  friend bool operator<(Object &lhs, Object &rhs) {
    return lhs.m_BoundingBox < rhs.m_BoundingBox;
  }
  int get_Object_ID() { return m_ID; };

  BoundingBox get_BoundingBox() const { return m_BoundingBox; }
  ObjectType get_Type() const { return objectType; }

private:
  void calculateObjectWidth() {
    if (objectType == ObjectType::Pedestrian) {
      m_width = 0.3;
    } else {
      m_width = m_BoundingBox.calculate_rear_width();
    }
  }
};

const uint16_t NumberofObjectsInList{32};
class ObjectList{
  private:
  std::array<Object ,NumberofObjectsInList> Objects;
  public:
  ObjectList(){
    for(int i{0} ; i<NumberofObjectsInList; ++i){
      Objects[i] = Object();        // todo assignment as move or in place creation
    }
  };
};

} // namespace Object_types