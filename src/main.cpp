#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Detection.h"

std::vector<Detection> generateDetections(int n);
void printDetection(int idx, const Detection& d);

int main() {
    srand(static_cast<unsigned>(time(nullptr))); //seed rng

    const int NUM_DETECTIONS = 5;
    std::vector<Detection> detections = generateDetections(NUM_DETECTIONS);

    std::cout << "=== Synthetic 3D Detections (Frame 0) ===\n\n";
    for (int i = 0; i < static_cast<int>(detections.size()); i++){
        printDetection(i, detections[i]);
    }
    return 0;
}