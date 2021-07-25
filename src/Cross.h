#pragma once
#include "Vector3D.h"

Vector3D Cross(Vector3D vec1, Vector3D vec2) {
	Vector3D crossVec;
	crossVec.x = vec1.y * vec2.z - vec1.z * vec2.y;
	crossVec.y = vec1.z * vec2.y - vec1.y * vec2.z;
	crossVec.z = vec1.x * vec2.y - vec1.y * vec2.x;
	return crossVec;
}

void Cross(float vec1[3], float vec2[3],float vec[3]) {
	vec[0] = vec[1] * vec[2] - vec[2] * vec[1];
	vec[1] = vec[2] * vec[0] - vec[0] * vec[2];
	vec[2] = vec[0] * vec[1] - vec[1] * vec[0];
}