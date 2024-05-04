#Compiler and Linker
CC          := cc

#The Target Binary Program
TARGET      := push_swap

#The Directories, Source, Includes, Objects, Binary and Resources
SRCDIR      := src
INCDIR      := inc
BUILDDIR    := obj
TARGETDIR   := bin
RESDIR      := res
SRCEXT      := c
OBJEXT      := o

#Flags, Libraries and Includes
CFLAGS      := -Wall -Werror -Wextra
LIBFT       := libft
LIB         := lib
TESTS       := tests
LIBFT.A     := libft.a

#---------------------------------------------------------------------------------
#DO NOT EDIT BELOW THIS LINE
#---------------------------------------------------------------------------------
SOURCES     := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS     := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.$(OBJEXT)))

#Default Make
all: directories $(LIBFT.A)  $(TARGET)

#Remake
re: fclean all
	@$(MAKE) -C $(LIB)/$(LIBFT) re

#Make the Directories
directories:
	@mkdir -p $(TARGETDIR)
	@mkdir -p $(BUILDDIR)

#Clean only Objects
clean:
	@$(RM) -rf $(BUILDDIR)
	@$(MAKE) -C $(LIB)/$(LIBFT) clean

#Full Clean, Objects and Binaries
fclean: clean
	@$(RM) -rf $(TARGETDIR)
	@$(MAKE) -C $(LIB)/$(LIBFT) fclean

#Link
$(TARGET): $(OBJECTS)
	$(CC) $^ $(LIB)/$(LIBFT)/$(LIB)/$(LIBFT.A) -o $(TARGETDIR)/$(TARGET) -g

$(LIBFT.A):
	@$(MAKE) -C $(LIB)/$(LIBFT) all

#Compile
$(BUILDDIR)/%.$(OBJEXT): $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c -o $@ $<

#Non-File Targets
.PHONY: all re clean fclean 
