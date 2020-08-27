CC := gcc
TARGET := bin
LIBS := -lpthread
OBJS := main.o

$(TARGET): $(OBJS)
	$(CC) $(LIBS) -o $@ $(OBJS)

clean:
	$(RM) $(TARGET) $(OBJS)
