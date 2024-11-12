/*
 * Copyright (C) 2015, Nils Moehrle
 * All rights reserved.
 *
 * This software may be modified and distributed under the terms
 * of the BSD 3-Clause license. See the LICENSE.txt file for details.
 */

#pragma once
#ifndef ACC_BVHTREE_HEADER
#define ACC_BVHTREE_HEADER

#include <deque>
#include <stack>
#include <cassert>
#include <algorithm>
#include <atomic>
#include <thread>
#include <vector>

#include "primitives.h"

namespace acc {

	class BVHTree {
	public:
		struct Hit {
			/* Parameter of the ray (distance of hit location). */
			float t;
			/* Index of the struck triangle. */
			std::size_t idx;
			/* Barycentric coordinates of hit location w.r.t. the triangle. */
			glm::vec3 bcoords;
		};

	private:
		struct Node {
			std::size_t first;
			std::size_t last;
			Node* left;
			Node* right;
			AABB aabb;
			Node(std::size_t first, std::size_t last)
				: first(first), last(last), left(nullptr), right(nullptr),
				aabb({ glm::vec3(inf), glm::vec3(-inf) }) {}
			bool is_leaf() const { return left == nullptr && right == nullptr; }
		};
		std::vector<std::size_t> indices;
		std::vector<Tri> tris;

		Node *root;

		std::pair<Node *, Node *> sbsplit(Node * node, std::vector<AABB> const & aabbs);
		std::pair<Node *, Node *> bsplit(Node * node, std::vector<AABB> const & aabbs);
		std::pair<Node *, Node *> ssplit(Node * node, std::vector<AABB> const & aabbs);
		void split(Node *node, std::vector<AABB> const & aabbs,
			std::atomic<int> * num_threads);

		bool intersect(Ray const & ray, Node const * node, Hit * hit) const;

	public:
		~BVHTree();

		/* Constructs the BVH tree using the Surface Area Heuristic as
		 * published in
		 * "On fast Construction of SAH-based Bounding Volume Hierarchies"
		 * by Ingo Wald (IEEE Symposium on Interactive Ray Tracing 2007)
		 *
		 * The mesh should be given as triangle index list and
		 * a vector containing the 3D positions. */
		BVHTree(std::vector<uint32_t> const & faces,
			std::vector<tdogl::Vertex> const & vertices,
			int max_threads = 2 * std::thread::hardware_concurrency());

		bool intersect(Ray ray, Hit * hit_ptr) const;
	};

}

#endif /* ACC_BVHTREE_HEADER */
