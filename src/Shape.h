#pragma once
#ifndef _SHAPE_H_
#define _SHAPE_H_

#include <string>
#include <vector>
#include "Light.h"

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>


using namespace std;

struct Hit
{
	Hit() : x(0), n(0), t(0) {}
	Hit(const glm::vec3& x, const glm::vec3& n, float t, int objIndex) { this->x = x; this->n = n; this->t = t; this->objIndex = objIndex; }
	glm::vec3 x; // position
	glm::vec3 n; // normal
	float t; // distance
	int objIndex;
};

class Shape
{
private:

public:
	glm::vec3 center;
	Shape();
	virtual void hit(glm::vec3 ray, glm::vec3 origin, vector<Hit>& hits, int objIndex);
	void translate(float x, float y, float z);
	glm::vec3 getColor(vector<Light> lights, Hit hit);
};

#endif
