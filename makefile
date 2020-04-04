# target: dependencies
# <tab> rule

# make (without arguments) executes first rule in file
# Ideally, one target for every object file and a target for final binary. 

UtPod: UtPod.o UtPodDriver.o
	g++ -o UtPod.exe UtPod.o UtPodDriver.o

UtPod.o: UtPod.cpp
	g++ -c -g UtPod.cpp -std=c++11

UtPodDriver.o: UtPodDriver.cpp
	g++ -c -g UtPodDriver.cpp -std=c++11 
