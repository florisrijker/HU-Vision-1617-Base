#include "IntensityImageStudent.h"

IntensityImageStudent::IntensityImageStudent() : IntensityImage() {

}

IntensityImageStudent::IntensityImageStudent(const IntensityImageStudent &other) : IntensityImage(other.getWidth(), other.getHeight()) {
	set(other);
}

IntensityImageStudent::IntensityImageStudent(const RGBImage &other) : IntensityImage(other.getWidth(), other.getHeight()) {
	set(other);
}

IntensityImageStudent::IntensityImageStudent(const int width, const int height) : IntensityImage(width, height) {
	set(width, height);
}

IntensityImageStudent::~IntensityImageStudent() {
	delete[] pixelStorage;
}

void IntensityImageStudent::set(const int width, const int height) {
	Intensity* newImage = new Intensity[width*height];
	int oldSize = this->getWidth() * this->getHeight();
	for (int i = 0; (oldSize ? i < (width*height) : i < oldSize); i++) {
		newImage[i] = (oldSize ? Intensity{} : pixelStorage[i]);
	}
	IntensityImage::set(width, height);

	pixelStorage = newImage;
}

void IntensityImageStudent::set(const IntensityImageStudent &other) {
	IntensityImage::set(other.getWidth(), other.getHeight());
	int maxSize = other.getWidth() * other.getHeight();
	pixelStorage = new Intensity[maxSize];	
	for (int i = 0; i < maxSize; i++) {
		pixelStorage[i] = other.getPixel(i);
	}
}

void IntensityImageStudent::set(const RGBImage &other) {
	IntensityImage::set(other.getWidth(), other.getHeight());
	int maxSize = other.getWidth() * other.getHeight();
	pixelStorage = new Intensity[maxSize];
	for (int i = 0; i < maxSize; i++) {
		RGB rgb = other.getPixel(i);
		pixelStorage[i] = (rgb.r + rgb.g + rgb.b) / 3;
	}
}

void IntensityImageStudent::setPixel(int x, int y, Intensity pixel) {
	pixelStorage[x + (y*IntensityImage::getWidth())] = pixel;
}

void IntensityImageStudent::setPixel(int i, Intensity pixel) {
	pixelStorage[i] = pixel;

}

Intensity IntensityImageStudent::getPixel(int x, int y) const {
	return pixelStorage[x + (y*IntensityImage::getWidth())];
}

Intensity IntensityImageStudent::getPixel(int i) const {
	return pixelStorage[i];
}
