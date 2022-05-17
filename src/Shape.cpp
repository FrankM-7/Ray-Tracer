#include "Shape.h"
#include <iostream>

using namespace std;

Shape::Shape() {
	this->center = glm::vec3(0, 0, 0);
	this->ka = glm::vec3(.2, .2, .2);
	this->kd = glm::vec3(.8, .7, .7);
	this->ks = glm::vec3(1.0, .9, .8);
	this->s = 200.0f;
	this->E = glm::mat4(1.0f);
}

void Shape::hit(glm::vec3 ray, glm::vec3 origin, vector<Hit>& hits, int objIndex) {
	cout << "should not go here" << endl;
}
bool Shape::intersects(glm::vec3 ray, glm::vec3 originRay, float distance) {
	cout << "should not go here" << endl;
	return false;
}

void Shape::translate(float x, float y, float z) {
	this->center = glm::vec3(x, y, z);
	E *= glm::translate(glm::mat4(1.0f), glm::vec3(x, y, z));
}
void Shape::scale(float x, float y, float z) {
	E *= glm::scale(glm::mat4(1.0f), glm::vec3(x, y, z));
}
glm::vec3 Shape::getColor(vector<Light> lights, Hit hit, glm::vec3 camPos, vector<Shape*> objects) {
	glm::vec3 c = ka;
	for (int i = 0; i < lights.size(); i++) {
		glm::vec3 lHat = glm::normalize(lights.at(i).position - hit.x);
		bool shadow = false;
		for (int j = 0; j < objects.size(); j++) {
			if (objects.at(j)->intersects(lHat, hit.x, glm::distance(hit.x, lights.at(i).position))) {
				shadow = true;
				break;
			}
		}
		if (shadow) continue;
		glm::vec3 nHat = glm::normalize(hit.n);
		glm::vec3 eHat = glm::normalize(camPos - hit.x);
		glm::vec3 hHat = glm::normalize(eHat + lHat);
		glm::vec3 cd = kd * glm::max(0.0f, glm::dot(lHat, nHat));
		glm::vec3 cs = ks * glm::max(0.0f, glm::pow(glm::dot(hHat, nHat), this->s));
		c += lights.at(i).intensity*(cs + cd);
	}
	c *= 255.0f;
	c = glm::clamp(c, 0.0f, 255.0f);

	return c;
}

void Shape::diffuse(float r, float g, float b) {
	this->kd = glm::vec3(r, g, b);
}
void Shape::ambient(float r, float g, float b) {
	this->ka = glm::vec3(r, g, b);
}
void Shape::shiny(float s) {
	this->s = s;
}
void Shape::specular(float r, float g, float b) {
	this->ks = glm::vec3(r, g, b);
}