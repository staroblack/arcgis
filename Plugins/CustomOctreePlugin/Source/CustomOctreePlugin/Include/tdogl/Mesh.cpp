#include "Mesh.h"

using namespace tdogl;

/*  Functions  */
// Constructor
//Mesh::Mesh(vector<Vertex> vertices, vector<GLuint> indices, vector<Texture> textures)
//{
//	this->vertices = vertices;
//	this->indices = indices;
//	this->textures = textures;
//
//	// Now that we have all the required data, set the vertex buffers and its attribute pointers.
//	//this->setupMesh();
//}
Mesh::Mesh(vector<Vertex> vertices, vector<unsigned int> indices)
{
	this->vertices = vertices;
	this->indices = indices;
}