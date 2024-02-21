add_library(3D-Math Vector3.cxx Matrix4.cxx)

target_include_directories(3D-Math INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})