
# common/tests/test0 directory makefile


fork: fork.c
	echo "Build fork."
	$(CC) $(DEBUGMODE) $(KERNELVER) $(SBC) $(APPM) $(PPCMODE) $(MYINCS) $@.c $(MYLIBS) -o $@ 


#.PHONY: clean
clean:
	$(RM) -rf *.o *~ core fork objchk*



