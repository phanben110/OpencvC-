compile : g++ main.cpp -o output `pkg-config --cflags --libs opencv`
run : ./output

