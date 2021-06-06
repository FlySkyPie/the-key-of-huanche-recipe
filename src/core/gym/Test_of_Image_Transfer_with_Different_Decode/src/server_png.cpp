#include <zmq.hpp>
#include <string>
#include <iostream>
#include <vector>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>



int main (int argc, char *argv[]) {
    //  Prepare our context and socket
    zmq::context_t context (1);
    zmq::socket_t socket (context, ZMQ_REP);
    socket.bind ("tcp://*:5556");

    while (true) {
        zmq::message_t request;
        socket.recv (&request); //  Wait for next request from client
        
        std::vector<char> vectordata(request.size());
        std::memcpy(vectordata.data(), request.data(), request.size());
        
        cv::Mat data_mat(vectordata,true);
        cv::Mat image(cv::imdecode(data_mat,CV_LOAD_IMAGE_COLOR)); //put 0 if you want greyscale

        //  Send reply back to client
        zmq::message_t reply (5);
        memcpy (reply.data (), "yeet!", 5);
        socket.send (reply);
    }
    return 0;
}
