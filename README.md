# vc-v4l2-opencv-test

Test project to see how well Vision Components IMX296 and proprietary driver function with OpenCV.


### TODO
Unfortunately it turned out that OpenCV doesn't handle certain functionalities of the camera well.
#### Controls 
1. Exposure
2. Gain
3. Check for trigger and flash mode? Must be set seperately since restart is required. 
4. Image Format Y10P (MIPI packed) is supported in V4L2 but not present in OpenCV videoio. Might be sufficient for now.

