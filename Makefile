CXX = g++
CXXFLAGS = -std=c++17 -Iinclude -Wall -Wextra

BUILD_DIR = build

TARGET = $(BUILD_DIR)/TMGR

SRCS = main.cpp \
	   TaskManager.cpp \
	   Task.cpp \
	   Logger.cpp 

OBJS = $(SRCS:%.cpp=$(BUILD_DIR)/%.o)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(BUILD_DIR)/%.o: %.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR):
	mkdir -p $@

clean:
	rm -rf $(BUILD_DIR)	