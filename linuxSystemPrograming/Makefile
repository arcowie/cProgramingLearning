CC=gcc

INCDIRS=includes/
LIBDIRS=./libs
APPCODEDIR=.

#Start Libary Variables and Flags
CLIBFLAGS=-c -fPIC
LIBSRC=$(foreach D,$(LIBDIRS),$(wildcard $(D)/*.c))
LIBOBJ=$(patsubst %.c,%.o,$(LIBSRC))
LIBS=$(patsubst %.c,%.so,$(LIBSRC))
CINCLUDEFLAGS=$(foreach D,$(INCDIRS),-I$(D))

#Start general application variables and Flags although
CFLAGS=-Wall -g $(CINCLUDEFLAGS)
RPATHFLAG=-Wl,-rpath=/home/arcowie/cProgramingLearning/linuxSystemPrograming/libs/
CLINKFLAGS=$(foreach D,$(LIBDIRS),-L$(D)) $(foreach D,$(LIBS),-l$(patsubst $(LIBDIRS)/lib%.so,%,$(D)))

#CFILES=$(foreach D,$(APPCODEDIR),$(wildcard $(D)/*.c))
#OBJS=$(patsubst %.c,%.o,$(CFILES))
CFILES=application.c
OBJS=application.o



BINARY=bin

all: $(BINARY)

$(BINARY): $(LIBS) $(CFILES) 
	$(CC) $(CFLAGS) -o $@ $(CFILES) $(RPATHFLAG) $(CLINKFLAGS)


#For building Libraries
%.so: %.c
	echo $(LIBSRC)
	$(CC) $(CLIBFLAGS)  $(CINCLUDEFLAGS) -o $(patsubst %.so,%.o,$@) $^
	$(CC) -shared -Wl,-soname,$@ -o $@ $(patsubst %.so,%.o,$@)
	rm $(LIBDIRS)/*.o


clean:
	rm ./libs/*.so
	#rm *.o
	rm bin
	
