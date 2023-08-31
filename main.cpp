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
    /**
     * Prevent OpenCV from creating a 3 channel matrix for greyscale image
     */
//    std::cout<<"Convert Flag : "<<cap.get(CAP_PROP_CONVERT_RGB)<<std::endl;
//    cap.set(CAP_PROP_CONVERT_RGB ,0);
//    std::cout<<"Convert Flag Toggle? : "<<cap.get(CAP_PROP_CONVERT_RGB)<<std::endl;WS


// gain and exposure must be set via v4l2, e.g., from commandline v4l2-ctl --set-ctrl exposure 
    std::cout << "Start grabbing" << std::endl
    std::string fileName = "";
    int counter = 0;
    while (counter < 1000)
    {
        cap.read(frame);
        if (frame.empty()) {
            std::cerr << "ERROR! blank frame grabbed\n";
            return -1;
        }
        //std::cout<<"Test:"<<counter;
        std::cout<<imwrite("/home/fue/test-runs/messung_binned3/gain0_exp1000_duty13_35ltr/"+std::to_string(counter)+".png",frame);
        counter++;
    }

    return 0;
}
