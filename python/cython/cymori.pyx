# define function from Clang header file
cdef extern from "mimori.h":
    ctypedef struct Suzuko:
        char mimoriSuzuko[1029]

    Suzuko makeMimoriSuzuko(int arg_num)

    # cdef char* addStr(cdef char* arg_str)

# define function executed by Python

def py_makeMimoriSuzuko(arg_num):
   return makeMimoriSuzuko(arg_num)

# def py_addStr(arg_str):
# 	return addStr(arg_str)
