#include <iostream>
#include <vector> //dynamic arrays in C++
#include <cstdlib> //rand(), srand()
#include <ctime> //time()

#include "Detection.h"


std::vector<Detection> generateDetections(int n){
    std::vector<Detection> detections;

    for (int i = 0; i < n; i++){
        Detection d;
        d.x = static_cast<float>(rand() % 100); //Simulates 100x100m scene
        d.y = static_cast<float>(rand() % 100); //Simulates 100x100m scene
        d.z = static_cast<float>(rand() % 5); // Most vehicles are on the ground (0–2 m), adding up to 5 m allows for small variance or pedestrians/objects

        d.width = 1.8f + static_cast<float>(rand() % 10) / 10.0f; // 1.8–2.7 m
        d.height = 1.5f + static_cast<float>(rand() % 5) / 10.0f; // 1.5–2.0 m
        d.depth = 4.0f + static_cast<float>(rand() % 20) / 10.0f; // 4.0–6.0 m

        d.confidence = 0.7f + static_cast<float>(rand() % 30) / 100.0f; //4.0 + 0–2.0
        
        detections.push_back(d);
    }
    return detections;
}

void printDetection(int idx, const Detection& d){
    std::cout<<" Detection "<<idx <<":\n"
             << "  Position   : (" << d.x << ", " << d.y << ", " << d.z << ") m\n"
             << "  Dimensions : " << d.width << "w x " << d.height << "h x " << d.depth << "d m\n"
             << "  Confidence : " << d.confidence << "\n\n";
}

