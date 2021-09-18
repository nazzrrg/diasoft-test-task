all:
	g++ -std=c++14 -o prog2 prog2.cpp -lcurl
	g++ -std=c++14 prog1.cpp -o prog1

clean:
	rm -rf prog1.o prog2.o prog1 prog2
test:
	./prog1 "{\"progname\":\"prog2\", \"url\":\"https://www.google.com\"}"