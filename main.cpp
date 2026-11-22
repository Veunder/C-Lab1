#include <iostream>
#include <opencv2/opencv.hpp>
#include <string>

void overlayImage(cv::Mat& background, const cv::Mat& foreground,cv::Point position) {
    for (int y = 0; y < foreground.rows; y++) {
        for (int x = 0; x < foreground.cols; x++) {
            cv::Vec4b pixel = foreground.at<cv::Vec4b>(y, x);

            int dstX = position.x + x;
            int dstY = position.y + y;

            if (dstX < 0 || dstY < 0 ||
                dstX >= background.cols ||
                dstY >= background.rows) {
                continue;
                }

            double alpha = pixel[3] / 255.0;

            cv::Vec3b& dst = background.at<cv::Vec3b>(dstY, dstX);

            for (int c = 0; c < 3; c++) {
                dst[c] = cv::saturate_cast<uchar>(
                    alpha * pixel[c] +
                    (1.0 - alpha) * dst[c]
                );
            }
        }
    }
}

int main() {
    cv::VideoCapture cap(0);
    cv::Mat frame;
    cv::VideoCapture gif("/home/veunder/CLionProjects/ML/GIF.gif");
    cv::Mat gifFrame;
    cv::Mat image = cv::imread("/home/veunder/CLionProjects/ML/img.png");
    bool timeFlag = false;
    bool gifFlag = false;
    while (cap.read(frame)) {
        cv::flip(frame, frame, 1);
        int key = cv::waitKey(1);
        if (key == 27) {
            break;
        }
        if (key == 'c') {
            cv::putText(frame, "Hello", cv::Point(0,30), cv::FONT_HERSHEY_SIMPLEX, 1.0, cv::Scalar(0, 255, 0), 1);
        }
        if (key == 'i') {
            gifFlag = !gifFlag;
        }
        if (key == 't') {
            timeFlag = !timeFlag;
        }
        if (timeFlag) {
            cv::putText(frame, std::format("{:%H:%M:%S}", std::chrono::zoned_time{std::chrono::current_zone(), std::chrono::system_clock::now()}), cv::Point(100, 30), cv::FONT_HERSHEY_PLAIN, 1.0, cv::Scalar(255, 0, 0), 1);
        }
        if (gifFlag && gif.read(gifFrame)) {
            if (!gif.read(gifFrame) || gifFrame.empty()) {
                gif.set(cv::CAP_PROP_POS_FRAMES, 0);
            }
            cv::resize(gifFrame, gifFrame, cv::Size(200, 200));
            gifFrame.copyTo(frame(cv::Rect(20, 200, gifFrame.cols, gifFrame.rows)));
        }
        cv::imshow("Camera", frame);
    }
    return 0;
}