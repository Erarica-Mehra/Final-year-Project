///////////////////////////////////////////////////////////////////////////////////////////////////////////////
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
#define snprintf sprintf_s	// Visual Studio on Windows comes with sprintf_s() instead 
using namespace cv;
using namespace std;

int main(int argc, char* argv[])
{

	int snapcnt=0;
	char cstr[256];
    VideoCapture cap(1); // open the video camera no. 0

    if (!cap.isOpened())  // if not success, exit program
    {
        cout << "Cannot open the video cam" << endl;
        return -1;
    }

   double dWidth = cap.get(CV_CAP_PROP_FRAME_WIDTH); //get the width of frames of the video
   double dHeight = cap.get(CV_CAP_PROP_FRAME_HEIGHT); //get the height of frames of the video

    cout << "Frame size : " << dWidth << " x " << dHeight << endl;

    namedWindow("MyVideo",CV_WINDOW_AUTOSIZE); //create a window called "MyVideo"

    while (1)
    {
        Mat frame;
		//cap.retrieve(frame);
		
        bool bSuccess = cap.read(frame); // read a new frame from video
		
         if (!bSuccess) //if not success, break loop
        {
             cout << "Cannot read a frame from video stream" << endl;
             break;
        }

        imshow("MyVideo", frame); //show the frame in "MyVideo" window
			char c=waitKey(30);
        if (c == 'c') //wait for 'esc' key press for 30ms. If 'esc' key is pressed, break loop
       {
         snapcnt=snapcnt+1;
		
			snprintf(cstr,sizeof(cstr)-1,"database\\snap%d.jpg",snapcnt);
			  imwrite(cstr,frame);

			  

		}
		else if (c==27)
		{    
break;
		}
    }
    return 0;

}