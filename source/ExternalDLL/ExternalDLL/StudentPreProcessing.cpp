#include "StudentPreProcessing.h"
#include "IntensityImageStudent.h"
#include "basetimer.h"
#include <iostream>
#include <fstream>


IntensityImage * StudentPreProcessing::stepToIntensityImage(const RGBImage &image) const {
	BaseTimer timer;
	timer.start();
	IntensityImageStudent* Intensity = new IntensityImageStudent(image);
	timer.stop();
	std::ofstream myfile;
	myfile.open("test.txt", std::ofstream::app);
	myfile << "Luminosity: [" << timer.elapsedSeconds() << ";" << timer.elapsedMilliSeconds() << ";" << timer.elapsedMicroSeconds() << "]\n";
	myfile.close();
	return Intensity;
}

IntensityImage * StudentPreProcessing::stepScaleImage(const IntensityImage &image) const {
	return nullptr;
}

IntensityImage * StudentPreProcessing::stepEdgeDetection(const IntensityImage &image) const {
	return nullptr;
}

IntensityImage * StudentPreProcessing::stepThresholding(const IntensityImage &image) const {
	return nullptr;
}