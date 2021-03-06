#pragma once
#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <algorithm>
using namespace std;
using namespace cv;
class Edge {
public:
	Edge();
	Edge(Mat img);
	~Edge();
	//기본 그레디언트 구하기
	void get_gradient(const Mat &img, Mat &dy, Mat &dx,int type);
	
	void gradient_magnitude(const Mat &dy, const Mat &dx, Mat &magnitude);

	Mat gradient_direction(const Mat &dy, const Mat &dx);
	//에지방향 보고 섰을때 왼쪽이 밝고 오른쪽이 어두움
	void edge_direction(const Mat &direction, Mat &out);

	//type: y-> y소벨, x -> x소벨
	//no padding
	void sobelOp(Mat &img, Mat &out, char type);

	void gaussian_blur(const Mat &img, Mat &out, float sigma);
	void gaussian_blur2(const Mat &img, Mat &out, double sigma);
	void log_blur(const Mat &img, Mat &out, float sigma);
	void zerocrossing_detection(const Mat &img, Mat &out, float sigma, int thresh);
private:
	int sobel_y[3][3] = { {-1,-2,-1},
							{0,0,0},
							{1,2,1} };
	int sobel_x[3][3] = { {-1,0,1},
							{-2,0,2},
							{-1,0,1} };
	int laplacian_mask[3][3] = { {0,1,0},
							{1,-4,1},
							{0,1,0} };



	//8-quantization && 3시방향이 0도
	uchar quantize_direction(float val);

	//padding 처리 필요
	Mat gaussian_mask(float sigma);

	Mat LOG_filter(float sigma);

	float limit(float a);

};
