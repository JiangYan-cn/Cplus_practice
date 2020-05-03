#include <iostream>
#include<opencv.hpp>

using namespace cv;

int main()
{
	Mat img = imread("pic/test.jpg");

	if (img.empty())
		return -1;

	namedWindow("Display");
	imshow("Display", img);
	waitKey(0);

}