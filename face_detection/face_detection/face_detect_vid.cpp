#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/core/core.hpp"
#include <iostream>
 #include <stdio.h>
 #include <conio.h>

 using namespace std;
 using namespace cv;

 /** Function Headers */
 void detectAndDisplay( Mat frame );


 /** Global variables */
 String face_cascade_name = "haarcascade_frontalface_alt.xml";
 
 CascadeClassifier face_cascade;

 string window_name = "Capture - Face detection";


 /** @function main */
 int main( int argc, const char** argv )
 {
  // CvCapture* capture;
   

   //-- 1. Load the cascades
   if( !face_cascade.load( face_cascade_name ) ){ printf("--(!)Error loading\n"); return -1; };
  
   //-- 2. Read the video stream


   VideoCapture cap(0); // open the video camera no. 0
//	 VideoCapture cap("Video2.mp4"); // open the video file for reading

    if (!cap.isOpened())  // if not success, exit program
    {
        cout << "Cannot open the video" << endl;
        return -1;
    }

	double fps = cap.get(CV_CAP_PROP_FPS); //get the frames per seconds of the video

   double dWidth = cap.get(CV_CAP_PROP_FRAME_WIDTH); //get the width of frames of the video
   double dHeight = cap.get(CV_CAP_PROP_FRAME_HEIGHT); //get the height of frames of the video

    cout << "Frame size : " << dWidth << " x " << dHeight << endl;


  
     while( true )
     {

		 Mat frame;
		 bool bSuccess = cap.read(frame); // read a new frame from video
		
         if (!bSuccess) //if not success, break loop
        {
             cout << "Cannot read a frame from video stream" << endl;
             break;
        }

 

   //-- 3. Apply the classifier to the frame
       if( !frame.empty() )
       { detectAndDisplay( frame );
	   }
       else
       { printf(" --(!) No captured frame -- Break!"); 
	   }
      int c = waitKey(33);
       if( (char)c == 27 ) {  return 0;}
      }
	 
   
  return 0;
 }

/** @function detectAndDisplay */
void detectAndDisplay( Mat frame )
{
  std::vector<Rect> faces;
  Mat frame_gray;
    CvPoint pt1, pt2;
  cvtColor( frame, frame_gray, CV_BGR2GRAY );
  equalizeHist( frame_gray, frame_gray );

  //-- Detect faces
                                            
  face_cascade.detectMultiScale( frame_gray, faces, 1.1, 5, CV_HAAR_DO_CANNY_PRUNING, Size(20, 20) );

  for( size_t i = 0; i < faces.size(); i++ )
  {
    

    // Find the dimensions of the face,and scale it if necessary
            pt1.x = faces[i].x;
            pt2.x = (faces[i].x + faces[i].width);
            pt1.y = faces[i].y;
            pt2.y = (faces[i].y + faces[i].height);

            // Draw the rectangle in the input image
           rectangle( frame, pt1, pt2, Scalar( 0, 0, 255 ), 3, 8, 0 );
    Mat faceROI = frame_gray( faces[i] );
    

    
  }
  //-- Show what you got
  imshow( window_name, frame );
 }