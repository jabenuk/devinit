cmake_minimum_required(VERSION 3.10)

project(%%DEVINIT_PROJECTNAME%%)

set(SRC "${CMAKE_CURRENT_LIST_DIR}/src")

add_executable(${PROJECT_NAME}
	"${SRC}/main.c"
)