#include <zmq.hpp>
#include <string>
#include <iostream>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

int main (int argc, char *argv[]) {
    //windows
    cv::namedWindow( "Display window", cv::WINDOW_AUTOSIZE );// Create a window for display.

    //  Prepare our context and socket
    zmq::context_t context (1);
    zmq::socket_t socket (context, ZMQ_REP);
    socket.bind ("tcp://*:5555");

    while (true) {
        zmq::message_t request;
        socket.recv (&request); //  Wait for next request from client

        cv::Mat image(600, 800, CV_8UC3, request.data());

        //  Send reply back to client
        zmq::message_t reply (5);
        memcpy (reply.data (), "yeet!", 5);
        socket.send (reply);
    }
    return 0;
}
