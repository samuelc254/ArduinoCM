ArduinoCM: build/main.o build/jsoncpp.o
	g++ build/main.o build/jsoncpp.o -o examples/ArduinoCM && cd examples && .\ArduinoCM -c externConfig.json -i alternativeSetup.json -o alternativeHeader.h && cd ..

build/main.o: src/main.cpp
	g++ -c src/main.cpp -o build/main.o

build/jsoncpp.o: src/jsoncpp.cpp
	g++ -c src/jsoncpp.cpp -o build/jsoncpp.o

clean:
	rm -f build/** example/ArduinoCM
