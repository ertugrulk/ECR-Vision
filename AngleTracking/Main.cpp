#include <string>
#include <iostream>
#include <vector>
#include <cmath>

// Include OpenCV Libs
#include <opencv2\core.hpp>
#include <opencv2\imgproc.hpp>
#include <opencv2\calib3d.hpp>
#include <opencv2\highgui.hpp>
#include <opencv2\videoio.hpp>

std::vector<cv::Point> findMaxArea(std::vector<std::vector<cv::Point>> contours) {

	double maxVal = 0;
	double current;

	std::vector<cv::Point> max;
	std::vector<cv::Point> temp;

	for (int i = 0; i < contours.size(); i++) {
		temp = contours[i];
		current = cv::contourArea(temp);
		if (maxVal < current) {
			maxVal = current;
			max = temp;
		}
	}

	return max;
}

cv::RotatedRect find_marker(cv::Mat image) {

	// Convert image to grayscale, blur it, and detect edges
	cv::Mat gray;
	cv::Mat blurr;
	cv::Mat edged;

	cv::cvtColor(image, gray, cv::COLOR_BGR2GRAY);
	cv::GaussianBlur(gray, blurr, cv::Size(5, 5), 0);
	cv::Canny(gray, edged, 35, 125);

	cv::imshow("edged", edged);

	//Find the contours
	std::vector<std::vector<cv::Point>> contours;

	cv::findContours(edged.clone(), contours, cv::RETR_LIST, cv::CHAIN_APPROX_NONE);

	std::vector<cv::Point> c = findMaxArea(contours);

	return cv::minAreaRect(c);
}


int main() {
	
	//What mode are we in
	bool isEnbeded = false;
	bool calabrate = true;

	//Mat for the images
	cv::Mat frame;

	//Marker
	cv::RotatedRect marker;

	cv::VideoCapture cap = cv::VideoCapture(0);
	

	while (true) {

		cap.read(frame);

		marker = find_marker(frame);

		cv::Point2f rect_points[4];
		marker.points(rect_points);
		for (int j = 0; j < 4; j++)
			line(frame, rect_points[j], rect_points[(j + 1) % 4], cv::Scalar(0, 255, 0), 1, 8);

		cv::imshow("Img", frame);

		cv::waitKey(30);
	}
	
	return 0;
}
