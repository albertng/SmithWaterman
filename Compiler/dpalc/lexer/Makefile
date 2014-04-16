LIB=
CSRC=
CGEN= dpal-lex.cpp
CFIL= ${CSRC} ${CGEN}
OBJS= ${CFIL:.cpp=.o}
CC=g++
CFLAGS = -g
FFLAGS = -odpal-lex.cpp
FLEX=flex ${FFLAGS}

all: lexer

lexer: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} ${LIB} -o lexer

dpal-lex.cpp: dpal.flex
	${FLEX} dpal.flex

%.o : %.cpp
	${CC} ${CFLAGS} -c $< -o $@

clean:
	rm -f lexer ${OBJS} dpal-lex.cpp
