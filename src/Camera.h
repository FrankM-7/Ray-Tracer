#pragma once
#ifndef _CAMERA_H
#define _CAMERA_H

#include <string>
#include <vector>

using namespace std;

class Camera
{
private:
	vector<float> rays;
public:
	Camera(int width, int height);

};

#endif
