#!/usr/bin/python3
def print_matrix_integer(matrix=[[]]):
    if not matrix:
        return

    for row in matrix:
        for i, num in enumerate(row):
            print("{}".format(num), end=" ")
        print()
