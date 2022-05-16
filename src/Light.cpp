#include "Light.h"
#include <iostream>

using namespace std;

Light::Light() {
	this->position = glm::vec3(0, 0, 0);
	this->intensity = 1.0f;
}

Light::Light(float x, float y, float z) {
	this->position = glm::vec3(x, y, z);
	this->intensity = 1.0f;
}