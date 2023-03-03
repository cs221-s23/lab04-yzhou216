PROG = lab04
OBJS = lab04.o
TMP = $(PROG) $(OBJS)

%.o: %.c
	gcc -c -g -o $@ $<

$(PROG): $(OBJS)
	gcc -g -o $@ $^

clean:
	rm -rf $(TMP)
