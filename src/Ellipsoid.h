#pragma once
#ifndef _ELLIPSOID_H_
#define _ELLIPSOID_H_

#include <string>
#include <vector>
#include "Shape.h"

class Ellipsoid : public Shape
{
private:
	float radius;
	glm::vec3 center;
public:
	Ellipsoid();
	void hit(glm::vec3 ray, glm::vec3 origin, vector<Hit>& hits, int objIndex) override;
	bool intersects(glm::vec3 ray, glm::vec3 originRay, float distance) override;
};

#endif
