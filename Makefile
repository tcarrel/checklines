EXE = lines

all: checklines.cpp
	g++ $< -o $(EXE)

clean:
	rm -f $(EXE)
