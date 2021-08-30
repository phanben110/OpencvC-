/*
 Email: phanben110@gmail.com 
*/

#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>

//using namespace cv;
//using std::cout;

int main( int argc, char** argv ) {
  
	// define thresh value 
	int thresh = 0; 
	int maxValue = 255; 
	cv::Mat image;
	cv::Mat dst;
	// init source image 
	char imgPath[10] = "img.jpg"; 
	
	// read image array 
	image = cv::imread(imgPath , 0); 
	
	// ussing algorithm threshold to convert image binary ( black and white ) 
	cv::threshold(image,dst, thresh, maxValue, cv::THRESH_BINARY); 
	
	// This is size matrix 
	int downWidth = 10;
	int downHeight = 10;
	cv::Mat resizedDown;
	
	//resize down
	cv::resize(dst, resizedDown, cv::Size(downWidth, downHeight),cv::INTER_LINEAR);
	
	// print debug
	std::cout << "M = " << std::endl << " "  << resizedDown << std::endl << std::endl; 
	std::cout << "width = " << std::endl << " "  << resizedDown.cols << std::endl << std::endl; 
	std::cout << "height = " << std::endl << " "  << resizedDown.rows << std::endl << std::endl;
	
	//convet format Mat for image to array 2D
	cv::Mat frame  ; 
	frame = resizedDown ;
	int numCols = frame.cols;
	int numRows = frame.rows;
	const int frameSize = frame.cols * frame.rows;
	int frameArray[10][10] ; 
	for (int x = 0; x < numCols; x++) {          // x-axis, cols
	    for (int y = 0; y < numRows; y++) {          // y-axis rows
	        double intensity = frame.at<uchar>(cv::Point(x, y));
		if( intensity == 255)
		{
	        frameArray[y][x] = 0 ; 
		}
		else if ( intensity == 0 ) 	
		{
		frameArray[y][x] = 1 ; 
		}
	
	  //std::cout << "intensity = " << intensity << std::endl;
	    }
	}
	
	// print result matrix 10x10
	std::cout << "That is result matrix 10x10, black = 0, white = 1 " << std::endl;
	for(int i=0; i<10; i++)
		{
			for(int j=0; j<10; j++)
	                {
				std::cout<<" "<<frameArray[i][j]<<" ";
	                }
			std::cout<<"\n";
	        }
	
	
	if(! image.data ) 
	{
	     std::cout <<  "Could not open or find the image" << std::endl ;
	      return -1;
	}
	
	//Display image 
	cv::namedWindow( "Source image", cv::WINDOW_AUTOSIZE );
	cv::imshow( "Source image", image );
	cv::waitKey(0);
	return 0;
}
