#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;


#define WIDTH 1920
#define HEIGHT 1080
#define FPS 30

int main(int argc, char const *argv[])
{
    VideoCapture cap(1);
    if (!cap.isOpened()) {
        cout << "Open Camera 0 failed !!!" << endl;
        return -1;
    }

    cap.set(CV_CAP_PROP_FOURCC, CV_FOURCC('M', 'J', 'P', 'G'));
    cap.set(CV_CAP_PROP_FPS, FPS);
    cap.set(CV_CAP_PROP_FRAME_WIDTH, WIDTH);
    cap.set(CV_CAP_PROP_FRAME_HEIGHT, HEIGHT);

    cout << "--- USB Camera Info ---" << endl;
    cout << " Width: "  << cap.get(CV_CAP_PROP_FRAME_WIDTH);
    cout << " Height: " << cap.get(CV_CAP_PROP_FRAME_HEIGHT);
    cout << " FPS: "    << cap.get(CV_CAP_PROP_FPS);
    cout << " FORMAT: " << cap.get(CV_CAP_PROP_FORMAT);
    cout << " FOURCC: " << (int)cap.get(CV_CAP_PROP_FOURCC);
    cout << endl;

    Size video_size = Size((int)cap.get(CV_CAP_PROP_FRAME_WIDTH), 
                           (int)cap.get(CV_CAP_PROP_FRAME_HEIGHT));
    VideoWriter writer;    
    writer.open("video.avi", CV_FOURCC('M', 'J', 'P', 'G'), FPS, video_size);

    namedWindow("MJPEG", 1);

    while(true)
    {
        Mat frame;
        cap >> frame;
        if (frame.empty()) 
            break;
        
        imshow("MJPEG", frame);
        writer << frame;

        if(waitKey(30) == 27) break;
    }

    return 0;
}
