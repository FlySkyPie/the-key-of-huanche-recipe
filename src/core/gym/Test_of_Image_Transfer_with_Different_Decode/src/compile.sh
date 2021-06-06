g++ server_bitmap.cpp -o server_bitmap -lzmq `pkg-config opencv --cflags --libs` -g -Wall
 
g++ server_png.cpp -o server_png -lzmq `pkg-config opencv --cflags --libs` -g -Wall

