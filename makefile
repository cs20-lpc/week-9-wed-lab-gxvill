all: build, run

build:
	g++ -std=c++17 driver.cpp -o driver

run:
	./driver
