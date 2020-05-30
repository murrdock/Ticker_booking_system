cd ..
cd server
gcc -c action.c
ar rvs action.a action.o
rm action.o
gcc server.c action.a
cd ..
cd client
gcc -c action.c
ar rvs action.a action.o
rm action.o
gcc client.c action.a
cd ..
