CC := gcc
LIBS := -lm
TARGET := bin
OBJS := main.o hashtable.o list.o

$(TARGET): $(OBJS)
	$(CC) $(LIBS) -o $@ $(OBJS)

clean:
	$(RM) $(TARGET) $(OBJS)
