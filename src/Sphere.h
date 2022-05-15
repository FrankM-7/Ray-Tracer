#pragma once
#ifndef _SPHERE_H_
#define _SPHERE_H_

#include <string>
#include <vector>
#include "Shape.h"

class Sphere : public Shape
{
private:
	float radius;
public:
	Sphere();
	void hit(glm::vec3 ray, glm::vec3 origin, vector<Hit>& hits, int objIndex) override;
	bool intersects(glm::vec3 ray, glm::vec3 originRay, float distance) override;
	void scale(float radius);

};

#endif
