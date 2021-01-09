################################################################################
# Master Makefile
#
# The Makefile only defines tools and recipes common to all variants. Variant
# recipes are included from variant Makefiles.
################################################################################
.DEFAULT_GOAL := all

# Makefile assignments don't strip whitespaces, so don't put trailing comments.
D_PROJ := $(patsubst %/,%,$(dir $(realpath $(lastword $(MAKEFILE_LIST)))))

# If not given, build sandbox by default.
VARIANT ?= sandbox

# If not given, build variant with default parameter
VAR_PARAM ?= default

# Project structure directory names are subject to change.
D_INC        := include
D_SRC        := source
D_TOOL       := tool
D_RECIPE     := recipe/$(VARIANT)
D_BUILD      := build/$(VARIANT)

# Well-known file names are subject to change.
F_KCONFIG        := KConfig
F_SUBDIR_MAKE    := subdir.mk
F_VAR_MAKE       := $(D_RECIPE)/variant.mk
F_VAR_PARAM      := $(D_RECIPE)/$(VAR_PARAM).config.mk

export VARIANT
export D_PROJ
export D_INC D_SRC D_TOOL D_RECIPE D_BUILD

# host tools
SHELL   := /bin/bash
ECHO    := @echo -e
LS      := @ls -B
MKDIR   := @mkdir -p
RM      := @rm -rf
CP      := @cp --parents
TOUCH   := @touch
CAT     := @cat

# function
# parses file $(F_SRC_MAKE) under a source directory and descend if necessary
# parameter $(1): source directory where $(F_SRC_MAKE) can be found
define SUBDIR_DESCEND =
DIR-y :=
SRC-y :=
D_HERE := $(1)
D_DEST := $(D_BUILD)/$(1)
include $(1)/$(F_SUBDIR_MAKE)
DIR-y := $$(addprefix $(1)/,$$(DIR-y))
SRC-y := $$(addprefix $(1)/,$$(SRC-y))
SRC_TREE += $$(SRC-y)
# recursion
$$(foreach D,$$(DIR-y),$$(eval $$(call $(0),$$(D))))
endef

# help item string template
# $(1) target name
# $(2) description
define HELP_ITEM =
'make $(1)\n\t$(2).\n'
endef

# The variant build config
include $(F_VAR_PARAM)

# After variant build config call function to discover sources.
SRC_TREE :=
OBJDIR_TREE :=
INCS-y := $(D_INC)
DEFS-y :=
CPPDEFS-y :=
LDLIBS-y :=
$(eval $(call SUBDIR_DESCEND,$(D_SRC)))
OBJDIR_TREE += $(D_BUILD)
OBJDIR_TREE += $(addprefix $(D_BUILD)/,$(sort $(dir $(SRC_TREE))))

# Builds variant target
.PHONY: all
all: variant tell
	$(ECHO) 'Variant "$(VARIANT)" built with "$(VAR_PARAM)" parameter.'

# Displays selected sources
.PHONY: tell
tell:
	$(ECHO) 'The following items are selected:'
	$(ECHO) '$(SRC_TREE:%=\t%\n)'

# Removes the build output of the variant
.PHONY: clean
clean:
	$(RM) $(D_BUILD)

# Creates directories for compiler outputs
$(OBJDIR_TREE):
	$(MKDIR) $(@)

# Creates the variant config file
.PHONY: config
config: D_KCONFIGLIB:=$(D_PROJ)/$(D_TOOL)/kconfiglib
config: export PATH := $(D_KCONFIGLIB)/bin:$(PATH)
config: export PYTHONPATH := $(D_KCONFIGLIB)/module:$(PYTHONPATH)
config: export CONFIG_ := MENU_
config: export KCONFIG_CONFIG := $(F_VAR_PARAM)
config: export MENUCONFIG_STYLE ?= aquatic
config:
	@menuconfig $(F_KCONFIG)

# Displays help
.PHONY: basic-help
basic-help:
	$(ECHO) $(call HELP_ITEM,all,Builds variant target)
	$(ECHO) $(call HELP_ITEM,all,Lists currently selected sources)
	$(ECHO) $(call HELP_ITEM,clean,Deletes build output)
	$(ECHO) $(call HELP_ITEM,config,Modifies variant build config)

# Variant recipes
include $(F_VAR_MAKE)
