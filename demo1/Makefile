app = program

FLAGS = -g -Wall `pkg-config --cflags gtk+-3.0`
LIBS = `pkg-config --libs gtk+-3.0` 


# 目标: 先决条件
${app}: cmd/main.c
		gcc $(FLAGS) -o ./bin/${app} cmd/main.c $(LIBS)

clean:
	rm ./bin/*