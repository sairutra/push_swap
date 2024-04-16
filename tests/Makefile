#Compiler and Linker
CC          := cc

#The Target Binary Program
TARGET      := push_swap_tests

#The Directories, Source, Includes, Objects, Binary and Resources
SRCDIR      := src
INCDIR      := inc
BUILDDIR    := obj
TARGETDIR   := bin
LOGDIR      := logs
RESDIR      := res
SRCEXT      := c
OBJEXT      := o

#Flags, Libraries and Includes
CFLAGS      := -Wall -Werror -Wextra
GNIRUT      := gnirut
PUSHSWAP    := push_swap
LIB         := lib
GNIRUT.A    := gnirut.a

#---------------------------------------------------------------------------------
#DO NOT EDIT BELOW THIS LINE
#---------------------------------------------------------------------------------
SOURCES     := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS     := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.$(OBJEXT)))

#Default Make
all: directories $(GNIRUT.A) $(TARGET) bubble

#execute bubble sort tests
bubble:
	cd $(TARGETDIR); ./$(TARGET)

#Remake
re: fclean all
	@$(MAKE) -C $(GNIRUT) re
	@$(MAKE) -C ../../$(PUSHSWAP) re

#Make the Directories
directories:
	@mkdir -p $(TARGETDIR)
	@mkdir -p $(BUILDDIR)
	@mkdir -p $(LOGDIR)

#Clean only Objects
clean:
	@$(RM) -rf $(BUILDDIR)
	@$(MAKE) -C $(GNIRUT) clean

#Full Clean, Objects and Binaries1
	@$(RM) -rf $(TARGETDIR)
	@$(RM) -rf $(BUILDDIR)
	@$(RM) -rf $(LOGDIR)
	@$(MAKE) -C $(GNIRUT) fclean

#Link
$(TARGET): $(OBJECTS)
	$(CC) $^ $(GNIRUT)/$(LIB)/$(GNIRUT.A) -o $(TARGETDIR)/$(TARGET) -g

$(GNIRUT.A):
	@$(MAKE) -C $(GNIRUT) all

#Compile
$(BUILDDIR)/%.$(OBJEXT): $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c -o $@ $<

#Non-File Targets
.PHONY: all re clean fclean 
