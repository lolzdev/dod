CFLAGS:=-Wall -Wextra -pedantic -std=c99
CPPFLAGS:=-Wall -Wextra -std=c++17
LIBS:=

SRC_C:=main.c
OBJ_C:=${SRC_C:.c=.o}

SRC_CPP:=main.cpp entity_extern.cpp
OBJ_CPP:=${SRC_CPP:.cpp=.oxx}

all: $(OBJ_C) $(OBJ_CPP)
	cc $(LIBS) $(CFLAGS) $(OBJ_C) -o bench1_c
	c++ $(LIBS) $(CFLAGS) $(OBJ_CPP) -o bench1_cpp

%.o: %.c
	cc $(CFLAGS) -c $< -o $@

%.oxx: %.cpp
	c++ $(CPPFLAGS) -c $< -o $@

.PHONY: clean
clean:
	@rm -rfv $(OBJ_C) $(OBJ_CPP) bench1_c bench1_cpp cachegrind*
