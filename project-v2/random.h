#pragma once
#include "header.h"
#include "perlin.h"

class Random
{
public:
	Random();

	static float NormalDistribution(float mi, float ro);
	static float NormalDistribution(float x, float mi, float ro);
};

