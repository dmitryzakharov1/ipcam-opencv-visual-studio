#include "opencv2/opencv.hpp"

using namespace cv;

int main(int, char)
{
	const std::string videoStreamAddress = "http://192.168.1.102/videostream.cgi?user=admin&pwd=qwertasdfg&x.mjpg";

	VideoCapture cap; // open the default camera
	cap.open(videoStreamAddress);

	if (!cap.isOpened()) // check if we succeeded
		return -1;
	Mat edges;
	namedWindow("IpCam stream", 1);
	for (;;)
	{
		Mat frame;
		cap >> frame; // get a new frame from camera
		imshow("IpCam stream", frame);
		if (waitKey(30) >= 0)
			break;
	}
	// the camera will be deinitialized automatically in VideoCapture destructor
	return 0;
}