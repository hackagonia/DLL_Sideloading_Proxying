# Define the compiler
CC = x86_64-w64-mingw32-gcc

# Define source and binary directories
SRC_DIR = ./Sources
BIN_DIR = ./Bin

# Define compiler flags
CFLAGS = -w -shared
LDFLAGS = -w

# Default target to run when you just type "make"
all: forward

# Target for the version with function forwarding
forward:
	@mkdir -p $(BIN_DIR)
	$(CC) $(SRC_DIR)/Dll_Legit.c $(CFLAGS) -o $(BIN_DIR)/OneCoreCommonProxyStub.dll
	$(CC) $(SRC_DIR)/Dll_Forward.c $(CFLAGS) -o $(BIN_DIR)/Mal.dll $(SRC_DIR)/Forward.def
	$(CC) $(SRC_DIR)/LoadDLL.c $(LDFLAGS) -o $(BIN_DIR)/LoadDLL.exe

# Clean up the compiled files
clean:
	rm -rf $(BIN_DIR)

