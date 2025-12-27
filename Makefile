CC = gcc
CFLAGS = -Wall -Wextra -pedantic

OBJS = objs
LIBS = libs
BINS = bins
SRCS = src

OUTLIB = libjson.so

all: setup compile link

setup:
	@echo "Creating subdirs..."

	@echo "  [+] Creating ./$(OBJS)"
	@mkdir -p ./$(OBJS)

	@echo "  [+] Creating ./$(LIBS)"
	@mkdir -p ./$(LIBS)

	@echo "  [+] Creating ./$(BINS)"
	@mkdir -p ./$(BINS)

	@echo "Done"

compile: setup
	@echo "Compiling sources..."

	@echo "  [+] Compiling ./$(SRCS)/json.c"
	@$(CC) $(CFLAGS) -fPIC -c ./$(SRCS)/json.c -o ./$(OBJS)/json.o

	@echo "Done"

link: setup compile
	@echo "Linking libraries..."

	@echo "  [+] Linking ./$(LIBS)/$(OUTLIB)"
	@$(CC) $(CFLAGS) -shared -o ./$(LIBS)/$(OUTLIB) ./$(OBJS)/json.o

	@echo "Done"

test: all
	@echo "Building test executable..."

	@echo "  [+] Compiling test/main.c"
	@$(CC) $(CFLAGS) -o ./$(BINS)/test_json ./test/main.c -L./$(LIBS) -ljson -Wl,-rpath,'$$ORIGIN/../$(LIBS)'

	@echo "Done"

clean:
	@echo "Cleaning..."
	@rm -rf ./$(OBJS) ./$(LIBS) ./$(BINS)
	@echo "Done"