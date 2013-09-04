DIRS := lib file mycat

all: linux

linux:
	for i in $(DIRS); do make -C $$i; done

clean:
	for i in $(DIRS); do \
		make -C $$i clean || exit 1; \
	done



	
