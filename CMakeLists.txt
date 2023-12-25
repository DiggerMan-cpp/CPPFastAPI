cmake_minimum_required(VERSION 3.27)
project(CPPFastAPI CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 17)

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
