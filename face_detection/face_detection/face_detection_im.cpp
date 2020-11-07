
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

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
   CvCapture* capture;
   Mat frame;

   //-- 1. Load the cascades
   if( !face_cascade.load( face_cascade_name ) ){ printf("--(!)Error loading\n"); return -1; };
  
   //-- 2. Read the video stream
   //capture = cvCaptureFromCAM( 0 );
//   if( capture )
//   {
//     while( true )
//     {
 //  frame = cvQueryFrame( capture );
frame=imread("a.jpg");

   //-- 3. Apply the classifier to the frame
       if( !frame.empty() )
       { detectAndDisplay( frame ); }
       else
       { printf(" --(!) No captured frame -- Break!"); }
waitKey();
      //int c = waitKey(10);
      // if( (char)c == 27 ) {  return 0;}
//      }
	 
//   }
//_getch();   
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