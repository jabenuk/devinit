cmake_minimum_required(VERSION 3.10)

project(devinit_template_cxx)

set(SRC "${CMAKE_CURRENT_LIST_DIR}/src")

add_executable(${PROJECT_NAME}
	"${SRC}/main.cc"
)