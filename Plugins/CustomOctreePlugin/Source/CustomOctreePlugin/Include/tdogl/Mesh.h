#pragma once

#ifndef TDOGLMESHHEADER
#define TDOGLMESHHEADER

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <glm/glm.hpp>

//#include <GL/glew.h>

//#include "Program.h"
//#include "Texture.h"

using namespace std;

namespace tdogl {
	struct Vertex
	{
		// Position
		glm::vec3 Position;
		// Normal
		glm::vec3 Normal;
		// TexCoords
		glm::vec2 TexCoords;
		// Pressure
		//glm::float32 Pressure;
	};

	class Mesh
	{
	public:
		/*  Mesh Data  */
		vector<Vertex> vertices;
		vector<unsigned int> indices;
		//vector<Texture> textures;

		/*  Functions  */
		// Constructor
		//Mesh(vector<Vertex> vertices, vector<unsigned int> indices, vector<Texture> textures);
		Mesh(vector<Vertex> vertices, vector<unsigned int> indices);
		// Render the mesh
		//void Draw(Program& program);

	private:
		/*  Render data  */
		//GLuint VAO, VBO, EBO;
		unsigned int VAO, VBO, EBO;
		/*  Functions    */
		// Initializes all the buffer objects/arrays
		//void setupMesh();
	};
}


#endif