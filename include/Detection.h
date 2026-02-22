#pragma once

// A single 3D bounding box detection from a sensor or detector
struct Detection {
    float x, y, z;              // center position in 3D space (meters)
    float width, height, depth; // bounding box dimensions (meters)
    float confidence;           // detection confidence score [0.0, 1.0]
};
