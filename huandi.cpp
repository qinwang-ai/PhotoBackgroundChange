#include<iostream>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
using namespace cv;
using namespace std;

bool fixed(int r, int g, int b) {
	if(200<=r && r<=255 && 200<=g && g<=255 && 200<=b && b<=255) {
		return true;
	}
	return false;
}

void changeColor(Mat &p) {
	int h = p.rows;
	int w = p.cols;
	uchar* data = p.data;
	for(int i = 0; i< h; i++) {
		for(int j = 0; j<w;j++) {
			int index = i*w + j;
			index *= 3;
			int b = data[index];
			int g = data[index + 1];
			int r = data[index + 2];
			if(fixed(r,g,b)) {
				cout<<"white"<<endl;
				p.data[index] = 0;
				p.data[index+1] = 0;
				p.data[index+2] = 255;
			}
		}
	}
}
int main(int argc,char *argv[]) {
	if(argc == 1) {
		cout<<"输入至少一个参数"<<endl;
		exit(0);
	}
	Mat photo = imread(argv[1]);
	imshow("a",photo);
	changeColor(photo);
	imshow("b",photo);
	imwrite("export.jpg", photo);
	waitKey(0);
	return 0;
}
