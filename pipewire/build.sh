
CXXFLAGS="-g -O0 -Wall -Wextra -Werror -std=c++17 -Wall -I/home/brian/src/pipewire/src -I/home/brian/src/pipewire/spa/include -I/home/brian/src/pipewire/builddir/src /home/brian/src/pipewire/builddir/src/pipewire/libpipewire-0.3.so"
echo "Compiling test1.c with flags: $CXXFLAGS"
g++ $CXXFLAGS src/test1.c -o build/test1 