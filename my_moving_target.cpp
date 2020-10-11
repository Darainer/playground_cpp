//
// Created by ryan on 04.04.20.
//
#include "object.hpp"
#include "templates.h"

int Object_types::Object::objectCount{0};

using Object_types::Point;

int main() {
  std::vector<Point> a(4, Point());
  for (Point &elem : a) {
    std::cout << "Point (x,y)  (" << elem.position_x << " , " << elem.position_y
              << ")" << std::endl;
  }
  auto is_an_object{Object_types::ObjectType::Vehicle};
  auto BB{Object_types::BoundingBox(a)};
  Object_types::Object obj{BB, is_an_object};
}
