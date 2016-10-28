#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-MacOSX
CND_DLIB_EXT=dylib
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/arrays.o \
	${OBJECTDIR}/bst.o \
	${OBJECTDIR}/chase_game.o \
	${OBJECTDIR}/count_beads.o \
	${OBJECTDIR}/digraph.o \
	${OBJECTDIR}/find_in_rotated.o \
	${OBJECTDIR}/heap.o \
	${OBJECTDIR}/linked_list.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/matrix.o \
	${OBJECTDIR}/max_diminishing_sub_array.o

# Test Directory
TESTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}/tests

# Test Files
TESTFILES= \
	${TESTDIR}/TestFiles/f8 \
	${TESTDIR}/TestFiles/f6 \
	${TESTDIR}/TestFiles/f1 \
	${TESTDIR}/TestFiles/f7 \
	${TESTDIR}/TestFiles/f5 \
	${TESTDIR}/TestFiles/f9 \
	${TESTDIR}/TestFiles/f10 \
	${TESTDIR}/TestFiles/f4 \
	${TESTDIR}/TestFiles/f2 \
	${TESTDIR}/TestFiles/f3

# Test Object Files
TESTOBJECTFILES= \
	${TESTDIR}/tests/testDigraph.o \
	${TESTDIR}/tests/testLinkedList.o \
	${TESTDIR}/tests/test_arrays.o \
	${TESTDIR}/tests/test_bst.o \
	${TESTDIR}/tests/test_chase_game.o \
	${TESTDIR}/tests/test_count_beads.o \
	${TESTDIR}/tests/test_find_in_rotated.o \
	${TESTDIR}/tests/test_heap.o \
	${TESTDIR}/tests/test_matrix.o \
	${TESTDIR}/tests/test_max_diminishing.o

# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/algorithms-c

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/algorithms-c: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.c} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/algorithms-c ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/arrays.o: arrays.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/arrays.o arrays.c

${OBJECTDIR}/bst.o: bst.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/bst.o bst.c

${OBJECTDIR}/chase_game.o: chase_game.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/chase_game.o chase_game.c

${OBJECTDIR}/count_beads.o: count_beads.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/count_beads.o count_beads.c

${OBJECTDIR}/digraph.o: digraph.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/digraph.o digraph.c

${OBJECTDIR}/find_in_rotated.o: find_in_rotated.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/find_in_rotated.o find_in_rotated.c

${OBJECTDIR}/heap.o: heap.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/heap.o heap.c

${OBJECTDIR}/linked_list.o: linked_list.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/linked_list.o linked_list.c

${OBJECTDIR}/main.o: main.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.c

${OBJECTDIR}/matrix.o: matrix.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/matrix.o matrix.c

${OBJECTDIR}/max_diminishing_sub_array.o: max_diminishing_sub_array.c
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/max_diminishing_sub_array.o max_diminishing_sub_array.c

# Subprojects
.build-subprojects:

# Build Test Targets
.build-tests-conf: .build-tests-subprojects .build-conf ${TESTFILES}
.build-tests-subprojects:

${TESTDIR}/TestFiles/f8: ${TESTDIR}/tests/test_arrays.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.c} -o ${TESTDIR}/TestFiles/f8 $^ ${LDLIBSOPTIONS}   -lcunit 

${TESTDIR}/TestFiles/f6: ${TESTDIR}/tests/test_bst.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.c} -o ${TESTDIR}/TestFiles/f6 $^ ${LDLIBSOPTIONS}   -lcunit 

${TESTDIR}/TestFiles/f1: ${TESTDIR}/tests/test_chase_game.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.c} -o ${TESTDIR}/TestFiles/f1 $^ ${LDLIBSOPTIONS}   -lcunit 

${TESTDIR}/TestFiles/f7: ${TESTDIR}/tests/test_count_beads.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.c} -o ${TESTDIR}/TestFiles/f7 $^ ${LDLIBSOPTIONS}   -lcunit 

${TESTDIR}/TestFiles/f5: ${TESTDIR}/tests/testDigraph.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.c} -o ${TESTDIR}/TestFiles/f5 $^ ${LDLIBSOPTIONS}   -lcunit 

${TESTDIR}/TestFiles/f9: ${TESTDIR}/tests/test_find_in_rotated.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.c} -o ${TESTDIR}/TestFiles/f9 $^ ${LDLIBSOPTIONS}   -lcunit 

${TESTDIR}/TestFiles/f10: ${TESTDIR}/tests/test_heap.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.c} -o ${TESTDIR}/TestFiles/f10 $^ ${LDLIBSOPTIONS}   -lcunit 

${TESTDIR}/TestFiles/f4: ${TESTDIR}/tests/testLinkedList.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.c} -o ${TESTDIR}/TestFiles/f4 $^ ${LDLIBSOPTIONS}   -lcunit 

${TESTDIR}/TestFiles/f2: ${TESTDIR}/tests/test_matrix.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.c} -o ${TESTDIR}/TestFiles/f2 $^ ${LDLIBSOPTIONS}   -lcunit 

${TESTDIR}/TestFiles/f3: ${TESTDIR}/tests/test_max_diminishing.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.c} -o ${TESTDIR}/TestFiles/f3 $^ ${LDLIBSOPTIONS}   -lcunit 


${TESTDIR}/tests/test_arrays.o: tests/test_arrays.c 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/test_arrays.o tests/test_arrays.c


${TESTDIR}/tests/test_bst.o: tests/test_bst.c 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/test_bst.o tests/test_bst.c


${TESTDIR}/tests/test_chase_game.o: tests/test_chase_game.c 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/test_chase_game.o tests/test_chase_game.c


${TESTDIR}/tests/test_count_beads.o: tests/test_count_beads.c 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/test_count_beads.o tests/test_count_beads.c


${TESTDIR}/tests/testDigraph.o: tests/testDigraph.c 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/testDigraph.o tests/testDigraph.c


${TESTDIR}/tests/test_find_in_rotated.o: tests/test_find_in_rotated.c 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/test_find_in_rotated.o tests/test_find_in_rotated.c


${TESTDIR}/tests/test_heap.o: tests/test_heap.c 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/test_heap.o tests/test_heap.c


${TESTDIR}/tests/testLinkedList.o: tests/testLinkedList.c 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/testLinkedList.o tests/testLinkedList.c


${TESTDIR}/tests/test_matrix.o: tests/test_matrix.c 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/test_matrix.o tests/test_matrix.c


${TESTDIR}/tests/test_max_diminishing.o: tests/test_max_diminishing.c 
	${MKDIR} -p ${TESTDIR}/tests
	${RM} "$@.d"
	$(COMPILE.c) -O2 -MMD -MP -MF "$@.d" -o ${TESTDIR}/tests/test_max_diminishing.o tests/test_max_diminishing.c


${OBJECTDIR}/arrays_nomain.o: ${OBJECTDIR}/arrays.o arrays.c 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/arrays.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/arrays_nomain.o arrays.c;\
	else  \
	    ${CP} ${OBJECTDIR}/arrays.o ${OBJECTDIR}/arrays_nomain.o;\
	fi

${OBJECTDIR}/bst_nomain.o: ${OBJECTDIR}/bst.o bst.c 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/bst.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/bst_nomain.o bst.c;\
	else  \
	    ${CP} ${OBJECTDIR}/bst.o ${OBJECTDIR}/bst_nomain.o;\
	fi

${OBJECTDIR}/chase_game_nomain.o: ${OBJECTDIR}/chase_game.o chase_game.c 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/chase_game.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/chase_game_nomain.o chase_game.c;\
	else  \
	    ${CP} ${OBJECTDIR}/chase_game.o ${OBJECTDIR}/chase_game_nomain.o;\
	fi

${OBJECTDIR}/count_beads_nomain.o: ${OBJECTDIR}/count_beads.o count_beads.c 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/count_beads.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/count_beads_nomain.o count_beads.c;\
	else  \
	    ${CP} ${OBJECTDIR}/count_beads.o ${OBJECTDIR}/count_beads_nomain.o;\
	fi

${OBJECTDIR}/digraph_nomain.o: ${OBJECTDIR}/digraph.o digraph.c 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/digraph.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/digraph_nomain.o digraph.c;\
	else  \
	    ${CP} ${OBJECTDIR}/digraph.o ${OBJECTDIR}/digraph_nomain.o;\
	fi

${OBJECTDIR}/find_in_rotated_nomain.o: ${OBJECTDIR}/find_in_rotated.o find_in_rotated.c 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/find_in_rotated.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/find_in_rotated_nomain.o find_in_rotated.c;\
	else  \
	    ${CP} ${OBJECTDIR}/find_in_rotated.o ${OBJECTDIR}/find_in_rotated_nomain.o;\
	fi

${OBJECTDIR}/heap_nomain.o: ${OBJECTDIR}/heap.o heap.c 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/heap.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/heap_nomain.o heap.c;\
	else  \
	    ${CP} ${OBJECTDIR}/heap.o ${OBJECTDIR}/heap_nomain.o;\
	fi

${OBJECTDIR}/linked_list_nomain.o: ${OBJECTDIR}/linked_list.o linked_list.c 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/linked_list.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/linked_list_nomain.o linked_list.c;\
	else  \
	    ${CP} ${OBJECTDIR}/linked_list.o ${OBJECTDIR}/linked_list_nomain.o;\
	fi

${OBJECTDIR}/main_nomain.o: ${OBJECTDIR}/main.o main.c 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/main.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main_nomain.o main.c;\
	else  \
	    ${CP} ${OBJECTDIR}/main.o ${OBJECTDIR}/main_nomain.o;\
	fi

${OBJECTDIR}/matrix_nomain.o: ${OBJECTDIR}/matrix.o matrix.c 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/matrix.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/matrix_nomain.o matrix.c;\
	else  \
	    ${CP} ${OBJECTDIR}/matrix.o ${OBJECTDIR}/matrix_nomain.o;\
	fi

${OBJECTDIR}/max_diminishing_sub_array_nomain.o: ${OBJECTDIR}/max_diminishing_sub_array.o max_diminishing_sub_array.c 
	${MKDIR} -p ${OBJECTDIR}
	@NMOUTPUT=`${NM} ${OBJECTDIR}/max_diminishing_sub_array.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} "$@.d";\
	    $(COMPILE.c) -O2 -Dmain=__nomain -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/max_diminishing_sub_array_nomain.o max_diminishing_sub_array.c;\
	else  \
	    ${CP} ${OBJECTDIR}/max_diminishing_sub_array.o ${OBJECTDIR}/max_diminishing_sub_array_nomain.o;\
	fi

# Run Test Targets
.test-conf:
	@if [ "${TEST}" = "" ]; \
	then  \
	    ${TESTDIR}/TestFiles/f8 || true; \
	    ${TESTDIR}/TestFiles/f6 || true; \
	    ${TESTDIR}/TestFiles/f1 || true; \
	    ${TESTDIR}/TestFiles/f7 || true; \
	    ${TESTDIR}/TestFiles/f5 || true; \
	    ${TESTDIR}/TestFiles/f9 || true; \
	    ${TESTDIR}/TestFiles/f10 || true; \
	    ${TESTDIR}/TestFiles/f4 || true; \
	    ${TESTDIR}/TestFiles/f2 || true; \
	    ${TESTDIR}/TestFiles/f3 || true; \
	else  \
	    ./${TEST} || true; \
	fi

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
