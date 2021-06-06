import zmq
import cv2
import time

'''
Case 1: transfer bitmap image
'''
print("Connecting to opencv server with bitmap…")
context1 = zmq.Context()
socket1 = context1.socket(zmq.REQ)
socket1.connect("tcp://localhost:5555")

timeSpend1 = []
#  Do 10 requests, waiting each time for a response
for request in range(10):
    image = cv2.imread("image.png", cv2.IMREAD_UNCHANGED)
    start = time.time()
    socket1.send(image.data)

    #  Get the reply.
    message = socket1.recv()
    end = time.time()
    timeSpend1.insert(0,end - start)

print("average time during: ", (sum( timeSpend1) / len( timeSpend1)) )

'''
Case 2: transfer png encoded image
'''
print("Connecting to opencv server with png…")
context2 = zmq.Context()
socket2 = context2.socket(zmq.REQ)
socket2.connect("tcp://localhost:5556")

timeSpend2 = []
#  Do 10 requests, waiting each time for a response
for request in range(10):
    f = open("image.png", "rb")
    strData = f.read()
    start = time.time()
    socket2.send(strData)

    #  Get the reply.
    message = socket2.recv()
    end = time.time()
    timeSpend2.insert(0,end - start)

print("average time during: ", (sum( timeSpend2) / len( timeSpend2)) )
