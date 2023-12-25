cmake_minimum_required(VERSION 3.27)
project(CPPFastAPI CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 17)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/runtime")
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
include_directories(include)

add_library(CPPFastAPI STATIC
        src/app.cpp
        src/BackgroundTasks.cpp
        src/CookieParams.cpp
        src/DependencyContainer.cpp
        src/Form.cpp
        src/Header.cpp
        src/JSONResponse.cpp
        src/PathParams.cpp
        src/request.cpp
        src/response.cpp
        src/Router.cpp
        src/UploadFile.cpp
        src/WebSocket.cpp
        src/QueryParams.cpp
)
set_target_properties(${PROJECT_NAME}
        PROPERTIES
        OUTPUT_NAME ${PROJECT_NAME}
        SUFFIX ".lib"
)