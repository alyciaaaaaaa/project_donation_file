complie : main.cpp
	g++ main.cpp donor.cpp -o dnt

run : dnt
	./dnt

clean : dnt
	rm dnt
