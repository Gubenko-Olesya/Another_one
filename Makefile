all: sort_bits

sort_bits: main.o random.o input.o copy_mass.o bit_compare.o raspechatka.o sort_quick.o sort_change.o check_array.o
	gcc main.o random.o input.o copy_mass.o bit_compare.o raspechatka.o sort_quick.o sort_change.o check_array.o -o sort_bits

main.o: main.cpp
	gcc -c main.cpp

random.o: random.cpp
	gcc -c random.cpp

input.o: input.cpp
	gcc -c input.cpp

copy_mass.o: copy_mass.cpp
	gcc -c copy_mass.cpp

bit_compare.o: bit_compare.cpp
	gcc -c bit_compare.cpp

raspechatka.o: raspechatka.cpp
	gcc -c raspechatka.cpp

sort_quick.o: sort_quick.cpp
	gcc -c sort_quick.cpp

sort_change.o: sort_change.cpp
	gcc -c sort_change.cpp

check_array.o: check_array.cpp
	gcc -c check_array.cpp

clean:
	rm -rf *.o sort_bits
