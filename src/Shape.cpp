#include "Shape.h"
#include <iostream>

using namespace std;

Shape::Shape() {
	cout << "is a shape" << endl;
}

bool Shape::hit(glm::vec3 ray) {
	cout << "should not go here" << endl;
	return false;
}