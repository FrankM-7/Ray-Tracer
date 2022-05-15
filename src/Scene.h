#pragma once
#ifndef _SCENE_H_
#define _SCENE_H_

#include <iostream>
#include <string>
#include <vector>
#include "Shape.h"
#include "Camera.h"
#include "Image.h"

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

using namespace std;

class Scene
{
private:
	vector<Shape*> objects;
	shared_ptr<Camera> camera;
	vector<Light> lights;
public:
	Scene();
	void addObject(Shape* object);
	void addCamera(shared_ptr<Camera> camera);
	void draw(shared_ptr<Image> image);
	void addLight(Light light);
};

#endif
