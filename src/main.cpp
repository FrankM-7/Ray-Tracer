#include <iostream>
#include <string>
#include <Windows.h>

#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Image.h"
#include "Camera.h"

using namespace std;

string RESOURCE_DIR = "../resources/"; // Where the resources are loaded from

int main(int argc, char **argv)
{
	//int sceneChoice = atoi(argv[1]);
	//int widthHeight = atoi(argv[2]);
	//string filename = argv[3];

	//auto image = make_shared<Image>(widthHeight, widthHeight);
	
	//for (int i = 0; i < widthHeight; i++) {
	//	image->setPixel(10, i, 255, 0, 0);
	//}
	// calculate ray directions for every pixel
	shared_ptr<Camera> cam = make_shared<Camera>(3, 3, 45, 5, 'z', -1);
	
	//image->writeToFile(filename);
	return 0;
}
