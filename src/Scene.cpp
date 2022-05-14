#include "Scene.h"



Scene::Scene() {

}

void Scene::addCamera(shared_ptr<Camera> camera) {
	this->camera = camera;
}

void Scene::addObject(shared_ptr<Shape> object) {
	this->objects.push_back(object);
}

void Scene::draw(shared_ptr<Image> image) {
	// for every ray
	int ctx = 0;
	int cty = 0;
	int i = 0;
	for (glm::vec3 ray : this->camera->rays) {
		vector<Hit> hits;
		// for every object
		for (int objInd = 0; objInd < objects.size(); objInd++) {
			// check if ray hits object, if yes it will store hits in hits vector<Hit>
			objects.at(objInd)->hit(ray, this->camera->origin, hits, objInd);
		}

		if (hits.size() == 0) {
			// color black 
		}
		else { // check which obj was hit first
			Hit lowestHit = hits.at(0);
			for (int i = 0; i < hits.size(); i++) {
				if (hits.at(i).t < lowestHit.t) {
					lowestHit = hits.at(i);
				}
			}
			// i have normal, eyevec, light vec. calc blinnphong
			objects.at(lowestHit.objIndex)->getColor(lights, lowestHit);
			image->setPixel(ctx, cty, 0, 155, 255);
		}
		ctx = (ctx + 1) % camera->width;
		if (ctx == 0) cty += 1;
	}
}

