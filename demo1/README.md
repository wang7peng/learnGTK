
## build

gcc `pkg-config --cflags gtk+-3.0` -o ./bin/program cmd/main.c `pkg-config --libs gtk+-3.0` 