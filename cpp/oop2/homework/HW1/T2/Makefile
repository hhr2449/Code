SRCS = main.cpp sum.cpp minus.cpp product.cpp divide.cpp
#SRCS是变量，等价于main.cpp sum.cpp minus.cpp product.cpp divide.cpp

all: $(SRCS)#单单使用make命令是就会执行这个all命令
	g++ $(SRCS) -DSUM -o main          #-D+宏名代表编译时定义一个宏，-o+文件名代表编译后生成的可执行文件的名字

debug: $(SRCS)
	g++ $(SRCS) -DDEBUG -o main

minus: $(SRCS)
	g++ $(SRCS) -DMINUS -o main

product: $(SRCS)
	g++ $(SRCS) -DPRODUCT -o main

divide: $(SRCS)
	g++ $(SRCS) -DDIVIDE -o main

clean:
	rm -f main *.o