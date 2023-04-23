app = program

# -no-pie 使生成的 exe 是无保护的
FLAGS = -g -Wall -no-pie `pkg-config --cflags gtk+-3.0`
LIBS = `pkg-config --libs gtk+-3.0`

${app}: cmd/main.c
		gcc $(FLAGS) -o ./bin/${app} cmd/main.c $(LIBS)

clean:
		rm ./bin/*