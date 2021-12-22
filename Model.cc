#include "Model.h"
#include <fstream>
#include <stdexcept>
#include <GL/gl.h>

Model::Model(const char *filename)
{
	std::ifstream file {filename};
	if (not file)
		throw std::runtime_error(
				std::string("Не могу открыть файл модели ")+
				std::string(filename));

	unsigned vertex_count, face_count;

	file >> vertex_count;
	_vertices.resize(vertex_count);
	for (auto &&v : _vertices)
		file >>v.x >> v.y >>v.z;

	file >> face_count;
	_faces.resize(face_count);
	_normals.resize(face_count);
	_tex_coords.resize(face_count);
	for (unsigned face = 0; face < face_count; ++face){
		unsigned face_vertex_count;
		file >> face_vertex_count;
		_tex_coords[face].resize(face_vertex_count);
		_faces[face].resize(face_vertex_count);
		for (auto &&f: _faces[face]) file >> f;
	}

	for (auto &&n: _normals) file >>n.x >>n.y >> n.z;

	for (auto &&f: _tex_coords)
		for (auto &&v: f)
		file >> v.s >> v.t;

	file.close();
}

void Model::draw()
{
	for (unsigned face = 0; face < _faces.size(); ++face){
		glBegin(GL_POLYGON);

		glNormal3fv(&_normals[face][0]);
		for (unsigned face_vertex = 0; face_vertex < _faces[face].size();
				++face_vertex){
			unsigned vertex = _faces[face][face_vertex];

			glTexCoord2fv(&_tex_coords[face][face_vertex][0]);
			glVertex3fv(&_vertices[vertex][0]);

		}
		glEnd();

	}
}
