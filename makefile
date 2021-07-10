CC=g++
CFLAGS=-Wall
EX_NAME=opencpt

#FILE=/a/Projects/OpenCpt
#FILE=/home/antonin/Share
FILE=/home/antonin/Documents/Personnel/Projets/OpenCpt
BIN=$(FILE)/bin
BUILD=$(FILE)/build
INCLUDE=$(FILE)/include
SRC=$(FILE)/src
TEST=$(FILE)/test

MAIN_PATTERN=($(CC) $(CFLAGS) $^ -o $(BIN)/$@)
TEST_PATTERN_ARITH=($(TEST)/$@ $(BUILD)/arithmetics.o)
BASE_COMPIL=arithmetics primalityTests basic_crypto
OTHER_COMPIL=scytale

all: $(BASE_COMPIL) $(EX_NAME) $(OTHER_COMPIL)

# ---------- Arithmetic base of the program ------------ 

arithmetics: $(SRC)/arithmetics.cpp  $(INCLUDE)/arithmetics.hpp
	$(CC) $(CFLAGS) $^ -c
	mv $@.o $(BUILD)/$@.o

primalityTests:  $(SRC)/primalityTests.cpp  $(INCLUDE)/primalityTests.hpp
	$(CC) $(CFLAGS) $^ -c
	mv $@.o $(BUILD)/$@.o

basic_crypto: $(SRC)/basic_crypto.cpp  $(INCLUDE)/basic_crypto.hpp
	$(CC) $(CFLAGS) $^ -c
	mv $@.o $(BUILD)/$@.o
# polynomial:$(SRC)/classes/polynomial.cpp $(INCLUDE)/classes/polynomial.hpp
# 	$(CC) $(CFLAGS) $^ -c
# 	mv $@.o $(BUILD)/$@.o

# ------------------------ Main ---------------------------

$(EX_NAME): $(SRC)/main.cpp $(BUILD)/arithmetics.o
	$(MAIN_PATTERN)


# --------------------- Test builds ----------------------

pgcd: $(TEST_PATTERN_ARITH)
	$(MAIN_PATTERN)

powm: $(TEST)/powm.cpp $(BUILD)/arithmetics.o
	$(MAIN_PATTERN)

chinese: $(TEST)/chinese.cpp $(BUILD)/arithmetics.o 
	$(MAIN_PATTERN)

bezoutc:$(TEST)/bezoutc.cpp $(BUILD)/arithmetics.o
	$(MAIN_PATTERN)

primeTestbasics:$(TEST)/primeTestbasics.cpp $(BUILD)/arithmetics.o $(BUILD)/primalityTests.o
	$(MAIN_PATTERN)

scytale: $(TEST)/scytale.cpp $(BUILD)/basic_crypto.o
	$(MAIN_PATTERN)

aks_base:$(SRC)/aks_base.cpp
	$(MAIN_PATTERN)

clean:
	rm $(BUILD)/*