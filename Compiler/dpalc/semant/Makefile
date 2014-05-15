CSRC= tree.cpp utils.cpp symtab.cpp consttab.cpp datatype.cpp
MAINSRC = semant.cpp
CGEN= dpal-lex.cpp dpal-parse.cpp
HGEN = dpal-parse.hpp
CFIL= ${CSRC} ${CGEN} ${MAINSRC}
HDRS = ${CSRC:.cpp=.hpp}
OBJS= ${CFIL:.cpp=.o}
CC=g++
CFLAGS = -g

all: semant

semant: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o semant

dpal-parse.cpp dpal-parse.hpp: dpal.y tree.hpp utils.hpp
	bison -d -o dpal-parse.cpp dpal.y

dpal-lex.cpp: dpal.flex tree.hpp dpal-parse.hpp
	flex -o dpal-lex.cpp dpal.flex

%.o : %.cpp dpal-parse.hpp
	${CC} ${CFLAGS} -c $< -o $@

clean:
	rm -f semant ${OBJS} ${CGEN} ${HGEN}
