GCC = g++

TARGET = final
OBJS = main.o bubblesort.o insertionSort.o mergeSort.o quickSort.o quickSortMedian.o selection.o quickSortMedianOfThree.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(GCC) -o $(TARGET) $(OBJS)

%.o: %.cpp main.hpp
	$(GCC) -c $< -o $@

clean:
	@echo "Removing everything but the source files"
	rm -f $(OBJS) $(TARGET)

.PHONY: all clean
