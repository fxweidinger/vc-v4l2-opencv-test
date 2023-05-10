#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/imgcodecs.hpp>
#include <cstdio>

using namespace cv;
int main() {
    Mat frame;
    VideoCapture cap(CAP_V4L2);
    cap.open(0);

    if(!cap.isOpened()){
        std::cerr<<"Error! Can't open camera";
        return -1;
    }

    std::cout<<"Convert Flag : "<<cap.get(CAP_PROP_CONVERT_RGB)<<std::endl;
    cap.set(CAP_PROP_CONVERT_RGB ,0);
    std::cout<<"Convert Flag Toggle? : "<<cap.get(CAP_PROP_CONVERT_RGB)<<std::endl;





    std::cout << "Start grabbing" << std::endl
         << "Press any key to terminate" << std::endl;
    //for (;;)
    //{
        // wait for a new frame from camera and store it into 'frame'
        cap.read(frame);
        // check if we succeeded
        if (frame.empty()) {
            std::cerr << "ERROR! blank frame grabbed\n";
            return -1;
        }
        // show live and wait for a key with timeout long enough to show images
        //std::ctime(reinterpret_cast<const time_t *>(std::chrono::system_clock::to_time_t(
        //                std::chrono::system_clock::now())))
        std::cout<<"Frame info: "<<frame.type()<<std::endl;
        imwrite("/home/fue/image-acq-tests/test08.jpg",frame);
    //}
    // the camera will be deinitialized automatically in VideoCapture destructor
    return 0;
}
