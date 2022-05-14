#pragma once
#ifndef _SPHERE_H_
#define _SPHERE_H_

#include <string>
#include <vector>
#include "Shape.h"

class Sphere : public Shape
{
private:

public:
	Sphere();
	bool hit(glm::vec3 ray) override;
};

#endif
