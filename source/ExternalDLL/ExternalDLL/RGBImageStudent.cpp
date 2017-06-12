#include "RGBImageStudent.h"

RGBImageStudent::RGBImageStudent() : RGBImage() {}

RGBImageStudent::RGBImageStudent(const RGBImageStudent &other) : RGBImage(other.getWidth(), other.getHeight()) {
	set(other);
}

RGBImageStudent::RGBImageStudent(const int width, const int height) : RGBImage(width, height) {
	set(width, height);
}

RGBImageStudent::~RGBImageStudent() {
	delete[] pixelStorage;
}

void RGBImageStudent::set(const int width, const int height) {
	RGB* newImage = new RGB[width*height];
	int oldSize = this->getWidth() * this->getHeight();
	for (int i = 0; (oldSize ? i < (width*height) : i < oldSize); i++) {
		newImage[i] = (oldSize ? RGB{} : pixelStorage[i]);
	}
	RGBImage::set(width, height);

	pixelStorage = newImage;
}

void RGBImageStudent::set(const RGBImageStudent &other) {
	RGBImage::set(other.getWidth(), other.getHeight());
	int maxSize = other.getWidth() * other.getHeight();
	pixelStorage = new RGB[maxSize];
	for (int i = 0; i < maxSize; i++) {
		pixelStorage[i] = other.getPixel(i);
	}
}

void RGBImageStudent::setPixel(int x, int y, RGB pixel) {
	pixelStorage[x + (y*RGBImage::getWidth())] = pixel;
}

void RGBImageStudent::setPixel(int i, RGB pixel) {
	pixelStorage[i] = pixel;
}

RGB RGBImageStudent::getPixel(int x, int y) const {
	return pixelStorage[x + (y*RGBImage::getWidth())];
}

RGB RGBImageStudent::getPixel(int i) const {
	return pixelStorage[i];
}