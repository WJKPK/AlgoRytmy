build:
	gcc *.c -O3 -o algoRytmy.out -lcriterion
test: build
	./algoRytmy.out
clean:
	rm -f *.out *o
