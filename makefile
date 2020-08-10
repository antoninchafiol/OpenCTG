CC=g++
CFLAGS=-Wall
EX_NAME=opencpt

FILE=/home/antonin/Share/crypto
BIN=$(FILE)/bin
BUILD=$(FILE)/build
INCLUDE=$(FILE)/include
SRC=$(FILE)/src
TEST=$(FILE)/test

MAIN_PATTERN=($(CC) $(CFLAGS) $^ -o $(BIN)/$@)
TEST_PATTERN_bARITH=($(TEST)/$@ $(BUILD)/basics_arithmetics.o)
TEST_PATTERN_mARITH=($(TEST)/$@ $(BUILD)/modular_arithmetics.o)

all: basics_arithmetics modular_arithmetics $(EX_NAME) powm

basics_arithmetics: $(SRC)/basics_arithmetics.cpp  $(INCLUDE)/basics_arithmetics.hpp
	$(CC) $(CFLAGS) $^ -c
	mv $@.o $(BUILD)/$@.o

modular_arithmetics: $(SRC)/modular_arithmetics.cpp  $(INCLUDE)/modular_arithmetics.hpp
	$(CC) $(CFLAGS) $^ -c
	mv $@.o $(BUILD)/$@.o

$(EX_NAME): $(SRC)/main.cpp $(BUILD)/basics_arithmetics.o
	$(MAIN_PATTERN)

pgcd: $(TEST_PATTERN_bARITH)
	$(MAIN_PATTERN)

powm: $(TEST)/powm.cpp $(BUILD)/modular_arithmetics.o
	$(MAIN_PATTERN)
 
clean:
	rm $(BUILD)/*