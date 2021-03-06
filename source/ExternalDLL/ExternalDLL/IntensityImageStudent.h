/*
* Copyright (c) 2015 DottedEye Designs, Alexander Hustinx, NeoTech Software, Rolf Smit - All Rights Reserved
* Unauthorized copying of this file, via any medium is strictly prohibited
* Proprietary and confidential
*/

#pragma once
#include "IntensityImage.h"
#include "RGBImage.h"
#include <iostream>
#include <math.h>
#include <algorithm>

class IntensityImageStudent : public IntensityImage {
public:
	IntensityImageStudent();
	IntensityImageStudent(const IntensityImageStudent &other);
	IntensityImageStudent(const RGBImage &other);
	IntensityImageStudent(const int width, const int height);
	~IntensityImageStudent();

	void set(const int width, const int height);
	void set(const IntensityImageStudent &other);
	void set(const RGBImage &other);

	void setPixel(int x, int y, Intensity pixel);
	void setPixel(int i, Intensity pixel);

	Intensity getPixel(int x, int y) const;
	Intensity getPixel(int i) const;


private:
	Intensity* pixelStorage;
};