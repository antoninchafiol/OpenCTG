CC=g++
CFLAGS=-Wall
EX_NAME=opencpt

FILE=/home/antonin/Documents/Personnel/Projets/crypto
#FILE=/home/antonin/Share/crypto
BIN=$(FILE)/bin
BUILD=$(FILE)/build
INCLUDE=$(FILE)/include
SRC=$(FILE)/src
TEST=$(FILE)/test

MAIN_PATTERN=($(CC) $(CFLAGS) $^ -o $(BIN)/$@)
TEST_PATTERN_ARITH=($(TEST)/$@ $(BUILD)/arithmetics.o)
BASE_COMPIL=arithmetics
OTHER_COMPIL=chinese bezoutc

all: $(BASE_COMPIL) $(EX_NAME) $(OTHER_COMPIL)

arithmetics: $(SRC)/arithmetics.cpp  $(INCLUDE)/arithmetics.hpp
	$(CC) $(CFLAGS) $^ -c
	mv $@.o $(BUILD)/$@.o

$(EX_NAME): $(SRC)/main.cpp $(BUILD)/arithmetics.o
	$(MAIN_PATTERN)

pgcd: $(TEST_PATTERN_ARITH)
	$(MAIN_PATTERN)

powm: $(TEST)/powm.cpp $(BUILD)/arithmetics.o
	$(MAIN_PATTERN)

chinese: $(TEST)/chinese.cpp $(BUILD)/arithmetics.o $(BUILD)/arithmetics.o
	$(MAIN_PATTERN)

bezoutc:$(TEST)/bezoutc.cpp $(BUILD)/arithmetics.o $(BUILD)/arithmetics.o
	$(MAIN_PATTERN)

clean:
	rm $(BUILD)/*