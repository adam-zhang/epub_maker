cmake_minimum_required(VERSION 2.8.11)

project(epub_maker)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

set(CMAKE_CXX_FLAGS "-std=c++11")
set(CMAKE_BUILD_TYPE Debug)
# Find the QtWidgets library
find_package(Qt5Widgets)
find_package(Qt5Network)
find_package(Qt5Xml)

# Tell CMake to create the helloworld executable
add_executable(epub_maker 
	main.cpp
	MainWindow.cpp
	MdiWidget.cpp
	CentralWidget.cpp
	DocumentDialog.cpp
	Document.cpp
	Helper.cpp
	)

# Use the Widgets module from Qt 5.
target_link_libraries(epub_maker 
	Qt5::Widgets
	Qt5::Network
	Qt5::Xml
	gumbo)
