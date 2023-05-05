#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <cstdio>

using namespace cv;
int main() {
    Mat frame;
    VideoCapture cap;

    cap.open(0);

    if(!cap.isOpened()){
        std::cerr<<"Error! Can't open camera";
        return -1;
    }
    //--- GRAB AND WRITE LOOP
    std::cout << "Start grabbing" << std::endl
         << "Press any key to terminate" << std::endl;
    for (;;)
    {
        // wait for a new frame from camera and store it into 'frame'
        cap.read(frame);
        // check if we succeeded
        if (frame.empty()) {
            std::cerr << "ERROR! blank frame grabbed\n";
            break;
        }
        // show live and wait for a key with timeout long enough to show images
        std::cout<<"Frame wasn't empty"<< std::endl;
    }
    // the camera will be deinitialized automatically in VideoCapture destructor
    return 0;
}
