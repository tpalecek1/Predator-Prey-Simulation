CXX = g++
CXXFLAGS = -g
CXXFLAGS += -Wall
CXXFLAGS += -std=c++0x
CXXFLAGS += -pedantic-errors

SRCS = main.cpp Ant.cpp Board.cpp Critter.cpp Doodlebug.cpp Menu.cpp validation.cpp

HEADERS = Ant.hpp Board.hpp Critter.hpp Doodlebug.hpp Menu.hpp validation.hpp

OBJS = main.o Ant.o Board.o Critter.o Doodlebug.o Menu.o validation.o

antdoodle: ${OBJS} ${HEADERS}
	${CXX} ${OBJS} -o antdoodle

${OBJS}:${SRCS}
	${CXX} ${CXXFLAGS} -c ${@:.o=.cpp}

clean:
	rm ${OBJS} antdoodle