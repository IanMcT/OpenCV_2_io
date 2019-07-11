#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

int main()
{
	cv::Mat img = cv::imread("lena.jpg");

	cv::Mat dst;
	cv::Sobel(img, dst, CV_32F, 1, 1);

	cv::imwrite("lena_sobel.png", dst);
//	cv::imshow("img", dst /256);
//	cv::waitKey();

	//video
//	cv::VideoCapture input("sample.mp4");

	cv::VideoCapture input(0);
//	cv::VideoWriter output(
//		"cars_sobel.avi",
//		CV_FOURCC('X','V','I','D'),
//		30,
//		cv::Size(input.get(CV_CAP_PROP_FRAME_WIDTH),
//			input.get(CV_CAP_PROP_FRAME_HEIGHT)));

	cv::VideoWriter output(
		"usbcamera_sobel.avi",
		CV_FOURCC('X','V','I','D'),
		30,
		cv::Size(input.get(CV_CAP_PROP_FRAME_WIDTH),
			input.get(CV_CAP_PROP_FRAME_HEIGHT)));

        cv::VideoWriter original(
                "usbcamera_original.avi",
                CV_FOURCC('X','V','I','D'),
                30,
                cv::Size(input.get(CV_CAP_PROP_FRAME_WIDTH),
                        input.get(CV_CAP_PROP_FRAME_HEIGHT)));

	for(;;)
	{
		if(!input.read(img))
			break;

		cv::Sobel(img, dst, CV_8U, 1, 1);

		output.write(dst);
		original.write(img);

		cv::imshow("img", img);
		char c = cv::waitKey(30);

		if(c == ' ')
			break;
	}
}
