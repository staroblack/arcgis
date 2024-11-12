#include "Model.h"

using namespace tdogl;
	
/*  Functions   */
// Constructor, expects a filepath to a 3D model.
Model::Model(string path)
{
	srand(static_cast <unsigned> (time(0)));
	this->loadModel(path);
}

// Draws the model, and thus all its meshes
//void Model::Draw(Program& program)
//{
//	for (unsigned int i = 0; i < this->meshes.size(); i++)
//	{
//		this->meshes[i].Draw(program);
//	}
//}

Mesh * tdogl::Model::GetMesh()
{
	//for (auto& indice : this->meshes[0].indices)
	//	cout << indice << endl;
	//for (auto& vertex : this->meshes[0].vertices)
	//	cout << Tocv(vertex.Position) << endl;
	return &this->meshes[0];
}


/*  Functions   */
// Loads a model with supported ASSIMP extensions from file and stores the resulting meshes in the meshes vector.
void Model::loadModel(string path)
{

	// Read file via ASSIMP
	Assimp::Importer importer;
	const aiScene *scene = importer.ReadFile(path, aiProcess_Triangulate  | aiProcess_GenBoundingBoxes|
		aiProcess_JoinIdenticalVertices| aiProcess_OptimizeGraph | aiProcess_OptimizeMeshes);
	

	// Check for errors
	if (!scene || scene->mFlags == AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) // if is Not Zero
	{
		//cout << "ERROR::ASSIMP:: " << importer.GetErrorString() << endl;
		return;
	}
	// Retrieve the directory path of the filepath
	this->directory = path.substr(0, path.find_last_of('/'));

	// Process ASSIMP's root node recursively
	this->processNode(scene->mRootNode, scene);
}

// Processes a node in a recursive fashion. Processes each individual mesh located at the node and repeats this process on its children nodes (if any).
void Model::processNode(aiNode* node, const aiScene* scene)
{
	// Process each mesh located at the current node
	for (unsigned int i = 0; i < node->mNumMeshes; i++)
	{
		// The node object only contains indices to index the actual objects in the scene.
		// The scene contains all the data, node is just to keep stuff organized (like relations between nodes).
		aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];

		this->meshes.push_back(this->processMesh(mesh, scene));
	}
	cout <<"Mesh Num: "<< node->mNumMeshes << endl;

	// After we've processed all of the meshes (if any) we then recursively process each of the children nodes
	for (unsigned int i = 0; i < node->mNumChildren; i++)
	{
		this->processNode(node->mChildren[i], scene);
	}
}

Mesh Model::processMesh(aiMesh *mesh, const aiScene *scene)
{
	// Data to fill
	vector<Vertex> vertices;
	vector<unsigned int> indices;
	//vector<Texture> textures;

	//cv::Vec3f max = 0;
	//cv::Vec3f min = 0;
	glm::vec3 min = glm::vec3(0);
	glm::vec3 max = glm::vec3(0);
		
	// Walk through each of the mesh's vertices
	for (unsigned int i = 0; i < mesh->mNumVertices; i++)
	{
		Vertex vertex;
		glm::vec3 vector;

		// Positions
		vector.x = mesh->mVertices[i].x;
		vector.y = mesh->mVertices[i].y;
		vector.z = mesh->mVertices[i].z;
		vector *= 0.001f;
		vertex.Position = vector;

		if (vector.x > max[0])
			max[0] = vector.x;
		if (vector.y > max[1])
			max[1] = vector.y;
		if (vector.z > max[2])
			max[2] = vector.z;
		if (vector.x < min[0])
			min[0] = vector.x;
		if (vector.y < min[1])
			min[1] = vector.y;
		if (vector.z < min[2])
			min[2] = vector.z;

		// Normals
		vector.x = mesh->mNormals[i].x;
		vector.y = mesh->mNormals[i].y;
		vector.z = mesh->mNormals[i].z;
		vertex.Normal = vector;

		// Texture Coordinates
		if (mesh->mTextureCoords[0]) // Does the mesh contain texture coordinates?
		{
			vertex.TexCoords = glm::vec2(0.0f, 0.0f);
		}
		else
		{//
			vertex.TexCoords = glm::vec2(0.0f, 0.0f);
		}

		vertices.push_back(vertex);
	}
	//cout <<"Vertices Num: "<< mesh->mNumVertices << endl;
	//cout << "Model MinXYZ: " << min << endl;
	//cout << "Model MaxXYZ: " << max << endl;

	// Now walk through each of the mesh's faces (a face is a mesh its triangle) and retrieve the corresponding vertex indices.
	for (unsigned int i = 0; i < mesh->mNumFaces; i++)
	{
		aiFace face = mesh->mFaces[i];
		// Retrieve all indices of the face and store them in the indices vector
		for (unsigned int j = 0; j < face.mNumIndices; j++)
		{
			indices.push_back(face.mIndices[j]);
		}
	}

	// Process materials
	//if (mesh->mMaterialIndex >= 0)
	//{
	//	aiMaterial* material = scene->mMaterials[mesh->mMaterialIndex];
	//	// We assume a convention for sampler names in the shaders. Each diffuse texture should be named
	//	// as 'texture_diffuseN' where N is a sequential number ranging from 1 to MAX_SAMPLER_NUMBER.
	//	// Same applies to other texture as the following list summarizes:
	//	// Diffuse: texture_diffuseN
	//	// Specular: texture_specularN
	//	// Normal: texture_normalN

	//	// 1. Diffuse maps
	//	vector<Texture> diffuseMaps = this->loadMaterialTextures(material, aiTextureType_DIFFUSE, "texture_diffuse");
	//	textures.insert(textures.end(), diffuseMaps.begin(), diffuseMaps.end());

	//	// 2. Specular maps
	//	vector<Texture> specularMaps = this->loadMaterialTextures(material, aiTextureType_SPECULAR, "texture_specular");
	//	textures.insert(textures.end(), specularMaps.begin(), specularMaps.end());
	//}

	// Return a mesh object created from the extracted mesh data
	//return Mesh(vertices, indices, textures);
	return Mesh(vertices, indices);
}
		