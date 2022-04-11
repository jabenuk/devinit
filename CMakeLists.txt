cmake_minimum_required(VERSION 3.10)

project(devinit 
	LANGUAGES C
)

set(SRC "${CMAKE_CURRENT_LIST_DIR}/src")

add_executable(${PROJECT_NAME}
	"${SRC}/main.c"

	"${SRC}/intl/dialogue.c"
	"${SRC}/intl/dialogue.h"

	"${SRC}/intl/info.h"

	"${SRC}/intl/util.c"
	"${SRC}/intl/util.h"
)