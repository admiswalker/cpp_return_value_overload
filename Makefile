
# Options: コンパイルオプション
CFLAGS  = -std=gnu++0x
CFLAGS += -Wall
CFLAGS += -O3

exe: main.cpp
	$(CXX) $< -o $@ $(CFLAGS)

