#!/usr/bin/python3


def n_queens(n):
    # create alias
    target_queens = n
    final_column = final_row = n - 1

    # Create iterators
    i_row = 0
    i_column = 0

    # Create control chessboard
    control_chessboard = [[ [] for i in range(n)] for i in range(n)] # >>> n * n

    # Create solutions n_queenss
    n_queens_solutions = []

    while !(entire_board_evaluated(i_row, i_column)):
        # iterators
        row = column = 0

        # Create chessboard
        chessboard = [[ [] for i in range(n)] for i in range(n)] # >>> n * n

        # Create controls
        get_out_chessboard = False
        control_temp_chessboard = [[ [] for i in range(n)] for i in range(n)] # >>> n * n

        # Create queens on board
        queens_on_board = 0

        # Fill Chessboard
        while in_chessboard(row, final_row):
            i_row = row
            while in_row_cheesboard(column, final_column):
                i_column = column
                position = { 'row': row, 'column': column }

                # Is validated position for queeen?
                if position_chessboard_validate(position, chessboard):
                    chessboard[row][column] = 'Q'
                    positions_validated.append(position)
                    queens_on_board += 1

                    # are all the possible queens on the board?
                    if queens_on_board == target_queens:
                        n_queens_solutions.append(get_solution(chessboard))
                    else:
                        # to the next row...
                        break

                # if position is not validate
                else:
                    # fill control tem chessboard with position invalidate
                    control_temp_chessboard[row][colum] = 'X'

                    # if the final column?
                    if column == final_columnn:
                        positions_validated # Aquí voy
                        # get_out chessboard
                        get_out_chessboard = True
                        break
                column += 1
            # we leave the board?
            if get_out_chessboard:
                break
            row += 1

#==== Validations

def position_chessboard_validate(position, chessboard):
    pass

def atack_by_column(queen, chessboard):
    for row in range(len(chessboard)):
        for column in range(len(chessboard[row])):
            pass


def atack_by_diagonal(queen, chessboard):
    pass

#==== Helpers

def in_chessboard(row, final_row):
    return row <= final_row

def in_row_cheesboard(column, final_column):
    return column <= final_column

def get_solution(chessboard):
    solution = []
    for row in range(len(chessboard)):
        for column in range(len(chessboard[row])):
            if chessboard[row][column] == 'Q':
                solution.append([row, column])

    return solution


def entire_board_evaluated(row, column):
    return row == 4 and column == 4












# Entry point
if __name__ == "__main__":
    import sys

    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        exit(1)
    else:
        option_queen = int(sys.argv[1]) if sys.argv[1].isdigit() else None
        if isinstance(option_queen, int):
            if option_queen >= 4:
                print('Start Program')
                n_queens(option_queen)
            else:
                print("N must be at least 4")
                exit(1)
        else:
            print("N must be a number")
            exit(1)