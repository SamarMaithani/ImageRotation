#include <iostream>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    int d, a;
    Mat image = imread("C:\\Users\\Shanks\\Pictures\\Ostankino Tower.jpg", IMREAD_UNCHANGED);
    if (image.empty())
    {
        cout << "ERROR!\n";
        cin.get();
        return -1;
    }
    string windowname = "Ostankino Tower";
    namedWindow(windowname, WINDOW_NORMAL);
    imshow(windowname, image);
    waitKey(0);
    destroyWindow(windowname);
    cout << "Enter the direction you want to rotate the Image:\n";
    cout << "Enter 1 to rotate Clockwise,\nEnter 2 to rotate Anti-Clockwise\n";
    cin >> d;
    cout << "\nEnter the angle you want to Rotate the image: ";
    cin >> a;
    if (d == 1)
        a = a * (-1);
    Point2f center((image.cols - 1) / 2.0, (image.rows - 1) / 2.0);
    Mat rot = getRotationMatrix2D(center, a, 1.0);
    Rect2f box = RotatedRect(Point2f(), image.size(), a).boundingRect2f();
    rot.at<double>(0, 2) += box.width / 2.0 - image.cols / 2.0;
    rot.at<double>(1, 2) += box.height / 2.0 - image.rows / 2.0;
    Mat dst;
    warpAffine(image, dst, rot, box.size());
    namedWindow(windowname, WINDOW_NORMAL);
    imshow(windowname, dst);
    waitKey(0);
    destroyWindow(windowname);
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
