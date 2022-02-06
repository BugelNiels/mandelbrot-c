# --- MACROS
# define program name
MAIN= mandelbrot

# define the C compiler to use
CC= gcc

# define any compile-time flags
CFLAGS= -O3

# define any libraries to link into executable
LIBS= -fopenmp

ifeq ($(OS),Windows_NT)
	MAIN= mandelbrot.exe
else
    LIBS += -lm
endif


# define C source files
SRCS= ${wildcard src/*.c} ${wildcard src/**/*.c}

# define C header files
HDRS= ${wildcard src/*.h} ${wildcard src/**/*.h} 

# --- TARGETS
all: ${MAIN}

#Builds the program
${MAIN}: ${SRCS} ${HDRS}
	@echo #
	@echo "-- BUILDING PROGRAM --"
	${CC} ${SRCS} ${CFLAGS} ${LIBS} -o ${MAIN}

clean:
	@echo #
	@echo "-- CLEANING PROJECT FILES --"
	$(RM) *.o ${MAIN}