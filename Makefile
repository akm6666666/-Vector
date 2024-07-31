# 指定编译器
CXX = g++

# 编译器选项
CXXFLAGS = -Wall -Wextra -std=c++11

# 目标可执行文件
TARGET = main

# 源文件
SRCS = main.cpp

# 生成的对象文件
OBJS = $(SRCS:.cpp=.o)

# 生成目标
all: $(TARGET)

# 链接目标
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# 编译源文件生成对象文件
%.o: %.cpp Vector.h Vector.inl
	$(CXX) $(CXXFLAGS) -c $< -o $@

# 清理
clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean

