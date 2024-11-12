/*
 * Copyright (C) 2015, Nils Moehrle
 * All rights reserved.
 *
 * This software may be modified and distributed under the terms
 * of the BSD 3-Clause license. See the LICENSE.txt file for details.
 */

#ifndef ACC_PRIMITIVES_HEADER
#define ACC_PRIMITIVES_HEADER

#include <limits>

#include "../tdogl/Mesh.h"

namespace acc {

	constexpr float inf = std::numeric_limits<float>::infinity();
	constexpr float eps = 1e-3;//std::numeric_limits<float>::epsilon();

	struct AABB {
		glm::vec3 min;
		glm::vec3 max;
	};

	struct Tri {
		glm::vec3 a;
		glm::vec3 b;
		glm::vec3 c;
	};

	struct Ray {
		glm::vec3 origin;
		glm::vec3 dir;
		float tmin;
		float tmax;
	};

	inline
	AABB operator+(AABB const & a, AABB const & b) {
		AABB aabb;
		for (std::size_t i = 0; i < 3; ++i) {
			aabb.min[i] = std::min(a.min[i], b.min[i]);
			aabb.max[i] = std::max(a.max[i], b.max[i]);
		}
		return aabb;
	}
	inline
	void operator+=(AABB & a, AABB const & b) {
		for (std::size_t i = 0; i < 3; ++i) {
			a.min[i] = std::min(a.min[i], b.min[i]);
			a.max[i] = std::max(a.max[i], b.max[i]);
		}
	}

	void calculate_aabb(Tri const & tri, AABB * aabb);

	float surface_area(AABB const & aabb);

	float mid(AABB const & aabb, std::size_t d);

	bool intersect(Ray const & ray, AABB const & aabb, float * tmin_ptr);

	bool intersect(Ray const & ray, Tri const & tri, float * t_ptr, glm::vec3 * bcoords_ptr);

}

#endif /* ACC_PRIMITIVES_HEADER */
