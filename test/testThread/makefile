outlib = ../../out/lib
outtmp = ../../out/tmp

gcc = g++

cflags = -I ../../util/concurrent/include/ -I ../../lang/include/ -I ../../io/include/ -I ../../util/include/

external = -lpthread \
           ../../out/lib/libobotcha.so \

files =
link =
libname	= threadtest

everything : $(libname)

$(libname): $(link)
	g++ -g -O0 *.cpp $(cflags)  $(external) -o mytest
