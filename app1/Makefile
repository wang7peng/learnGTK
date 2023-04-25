app = programIM

FLAGS = -g -Wall -no-pie `pkg-config --cflags gtk+-3.0`
LIBS = `pkg-config --libs gtk+-3.0`

.PHONY:all
all:bin ${app}
bin:
		mkdir $@

${app}: cmd/main.c
		gcc $(FLAGS) -o ./bin/${app} cmd/main.c $(LIBS)

clean:
		rm -r ./bin