#include "opencv2/opencv.hpp"
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <stdint.h>

int main(int argv, char** argc)
{
	cv::Mat frame;

	cv::VideoCapture vid;
	
	vid.open("http://10.50.16.92:8000/stream.mjpg");
	

	if (!vid.isOpened()) {
		return -1;
	}

	while (vid.read(frame)) {
		
		cv::imshow("Stream", frame);
		if (cv::waitKey(1000 / 30) >= 0) {
			break;
		}
	}
	return 1;
}
