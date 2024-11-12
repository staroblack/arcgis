#pragma once

#ifndef TDOGLMODELHEADER
#define TDOGLMODELHEADER

#include "../CustomOctree.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <map>
#include <vector>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

//#include <GL/glew.h>

#include "Mesh.h"


class CustomPoint;

namespace tdogl {

	class Model
	{
	public:
		/*  Functions   */
		// Constructor, expects a filepath to a 3D model.
		Model(string path);

		// Draws the model, and thus all its meshes
		//void Draw(Program& program);

		Mesh* GetMesh();

	private:
		/*  Model Data  */
		vector<Mesh> meshes;
		string directory;

		/*  Functions   */
		// Loads a model with supported ASSIMP extensions from file and stores the resulting meshes in the meshes vector.
		void loadModel(string path);

		// Processes a node in a recursive fashion. Processes each individual mesh located at the node and repeats this process on its children nodes (if any).
		void processNode(aiNode* node, const aiScene* scene);

		Mesh processMesh(aiMesh* mesh, const aiScene* scene);
	};
}
#endif