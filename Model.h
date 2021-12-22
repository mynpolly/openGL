/*
 * Model.h
 *
 *  Created on: 16 дек. 2021 г.
 *      Author: polly
 */

#ifndef MODEL_H_
#define MODEL_H_

#include <vector>
#include <glm/glm.hpp>



class Model {
protected:
	std::vector<glm::vec3>_vertices;
	std::vector<std::vector<unsigned>> _faces;
	std::vector<glm::vec3> _normals;
	std::vector<std::vector<glm::vec2>> _tex_coords;


public:
	Model(const char *filename);
	virtual ~Model() = default;

	void draw();//с помощью него рисуется вся модель

};

#endif /* MODEL_H_ */
