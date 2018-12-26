build:
	gcc *.c -O2 -o algoRytmy.out -lcriterion
test: build
	./algoRytmy.out
clean:
	rm -f *.out *o 
