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
	Hit() : x(0), n(0), t(0), objIndex(0) {}
	Hit(const glm::vec3& x, const glm::vec3& n, float t, int objIndex) { this->x = x; this->n = n; this->t = t; this->objIndex = objIndex; }
	glm::vec3 x; // position
	glm::vec3 n; // normal
	float t; // distance
	int objIndex;
};

class Shape
{
private:
	glm::vec3 ka;
	glm::vec3 kd;
	glm::vec3 ks;
	float s;
public:
	glm::mat4 E;

	glm::vec3 center;
	Shape();
	virtual void hit(glm::vec3 ray, glm::vec3 origin, vector<Hit>& hits, int objIndex);
	virtual bool intersects(glm::vec3 ray, glm::vec3 originRay, float distance);

	void translate(float x, float y, float z);
	void scale(float x, float y, float z);
	void diffuse(float r, float g, float b);
	void ambient(float r, float g, float b);
	void shiny(float s);
	void specular(float r, float g, float b);

	glm::vec3 getColor(vector<Light> lights, Hit hit, glm::vec3 camPos, vector<Shape*> objects);
};

#endif
