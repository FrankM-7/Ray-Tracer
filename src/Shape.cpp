#include "Shape.h"
#include <iostream>

using namespace std;

Shape::Shape() {
	this->center = glm::vec3(0, 0, 0);
	cout << "is a shape" << endl;
}

void Shape::hit(glm::vec3 ray, glm::vec3 origin, vector<Hit>& hits, int objIndex) {
	cout << "should not go here" << endl;
}

void Shape::translate(float x, float y, float z) {
	this->center = glm::vec3(x, y, z);
}