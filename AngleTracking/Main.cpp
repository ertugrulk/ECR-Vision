#include <string>;
#include <iostream>

// Include OpenCV Libs
#include <opencv2\core.hpp>
#include <opencv2\imgproc.hpp>
#include <opencv2\calib3d.hpp>
#include <opencv2\highgui.hpp>
#include <opencv2\videoio.hpp>

int main() {
	
	//What mode are we in
	bool isEnbeded = false;
	bool calabrate = true;

	//Mat for the images
	cv::Mat frame;

	cv::VideoCapture cap = cv::VideoCapture(0);
	
	int temp;

	std::cin >> temp;

	return 0;
}
