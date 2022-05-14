#pragma once
#ifndef _SCENE_H_
#define _SCENE_H_

#include <iostream>
#include <string>
#include <vector>
#include "Shape.h"
#include "Camera.h"

using namespace std;

class Scene
{
private:
	vector<shared_ptr<Shape>> objects;
	shared_ptr<Camera> camera;
public:
	Scene();
	void addObject(shared_ptr<Shape> object);
	void addCamera(shared_ptr<Camera> camera);
	void draw();
};

#endif
