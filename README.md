# 3D Multi-Object Tracker

A 3D multi-object tracker implemented in modern C++17 with Python integration for perception pipelines. Designed to match the requirements of autonomous vehicle perception roles.

The tracker processes 3D bounding boxes, performs data association, manages track lifecycles, integrates ML detections via PyTorch, and supports multithreading and performance profiling.

## Technologies
- **C++17** — core implementation
- **Eigen** — matrix operations for the Kalman filter
- **CMake** — build system
- **pybind11** — Python/C++ bridge
- **PyTorch** — pre-trained 3D object detectors (PointPillars, CenterPoint)
- **Open3D / Matplotlib** — 3D visualization of trajectories
- **LLDB / AddressSanitizer** — debugging

## Build
```bash
mkdir build && cd build
cmake ..
make -j$(nproc)
```

## Architecture

### Detection
```cpp
struct Detection {
    float x, y, z;
    float width, height, depth;
    float confidence;
};
```

### Kalman Filter — Constant Acceleration (CA) model
- **State**: `[x, y, z, vx, vy, vz, ax, ay, az]ᵀ`
- **Measurement**: `[x, y, z]ᵀ`
- Eigen-based `predict()` and `update()` methods

### Data Association
3D IoU cost matrix → Hungarian algorithm for optimal track-detection matching

### Multithreading
Parallel track prediction and update via `std::thread`; performance logged with `std::chrono`

## Project Phases

| Phase | Topic |
|-------|-------|
| 1 | Project setup + synthetic detection generator |
| 2 | 3D constant-acceleration Kalman filter |
| 3 | Track class + TrackManager lifecycle |
| 4 | Data association (greedy → Hungarian) |
| 5 | Multithreading + FPS/memory profiling |
| 6 | PyTorch detector integration via pybind11 |
| 7 | Visualization (Open3D/Matplotlib) + MOTA metrics |

## Metrics
MOTA, ID switches, track fragmentation — evaluated against edge cases including crossing objects, missing detections, and object disappearance.

## Author
Saumit Vedula
