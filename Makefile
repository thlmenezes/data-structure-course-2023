# @author Thales Lima Menezes
# @github thlmenezes
# @date   29/07/2021
#
# This script was written by thlmenezes and
# is released to the public domain
#
##################################################################
###########Variables
#  SRC_DIR equals source code folder
#  sources has a string with the address of all source files (*.cpp)
#  objects has a string with the address of all object files (*.o)
#  CC equals compiler
#  CFLAGS equals compiling flags
#  LFLAGS equals linking flags
#  ':=' the non-recursive way of initializing a variable
#  '$^' used to insert all the rule' dependencies in the command
##################################################################
SRC_DIR := src
INC_DIR := src
sources := $(wildcard $(SRC_DIR)/*.c)
headers := $(wildcard $(INC_PATH)/*.h)
objects := $(sources:$(SRC_DIR)/%.c=obj/%.o)
deps    := $(objects:.o=.d)
files   := $(objects) $(deps) main test tests/main.o

tfiles := $(wildcard tests/*.c)
tobjects := $(tfiles:.c=.o)

CC       := gcc
CFLAGS   := -g -Wall -pedantic

main: $(objects)
	$(LINK.o) $^ -o $@

test: $(tobjects) $(filter-out obj/main.o, $(objects))
	$(LINK.o) $^ -o $@

tests/%.o: tests/%.c
	$(COMPILE.c) -I $(INC_DIR) $(OUTPUT_OPTION) $<
##################################################################
###########Building Rules
#  Used when compiling an object for COMPILE
#	'$<' means to use the string that's to the right of the ':'
#	'$@' means to use the string that's to the left of the ':'
#  Every "*.cpp" in the folder "$(SRC_DIR)" must compile in to an
#  "*.o" in the "obj" and has a dependecy to it's matching
#  source file.
#  @<command> sillences command output
#  @mkdir obj guarantees the obj dir exists before compiling
##################################################################
obj/%.o: $(SRC_DIR)/%.c
	@mkdir obj || true
	$(COMPILE.c) -I $(INC_DIR) $(OUTPUT_OPTION) $<

clean:
	rm $(files)
	@rmdir obj

-include $(deps)
