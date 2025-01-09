cmake_minimum_required(VERSION 3.10)
project(CameraApp)

# Find wxWidgets
find_package(wxWidgets REQUIRED COMPONENTS core base)
include(${wxWidgets_USE_FILE})

# Find OpenCV
find_package(OpenCV REQUIRED)

# Add the executable
add_executable(CameraApp camera_app.cpp)
target_link_libraries(CameraApp ${wxWidgets_LIBRARIES} ${OpenCV_LIBS})
