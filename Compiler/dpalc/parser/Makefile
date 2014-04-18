CSRC= tree.cpp utils.cpp
CGEN= dpal-lex.cpp dpal-parse.cpp
CFIL= ${CSRC} ${CGEN}
OBJS= ${CFIL:.cpp=.o}
CC=g++
CFLAGS = -g
FFLAGS = -o dpal-lex.cpp
FLEX=flex ${FFLAGS}
BFLAGS = -d -o dpal-parse.cpp
BISON=bison ${BFLAGS}

all: parser

parser: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o parser

dpal-parse.cpp dpal-parse.hpp: dpal.y
	${BISON} dpal.y

dpal-lex.cpp: dpal.flex dpal-parse.hpp
	${FLEX} dpal.flex

%.o : %.cpp
	${CC} ${CFLAGS} -c $< -o $@

clean:
	rm -f parser ${OBJS} ${CGEN}
