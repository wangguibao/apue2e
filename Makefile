DIRS := lib file

all: linux

linux:
	for i in $(DIRS); do make -C $$i; done

clean:
	for i in $(DIRS); do \
		make -C $$i clean || exit 1; \
	done



	
