# sweep ming game board generator

#
#N refers to the number of targets
# rows and cols are the board size
import random
def count_mine(board,i,j):
    res = 0
    for a in range(i-1,i+2):
        for b in range(j-1,j+2):
            if board[a][b] == 9:
                res += 1
    #print res
    return res

def myprint(board):
    for i in board:
        print i

def generate(N, rows, cols):
    #rows = len(board)
    #cols = len(board[0])
    board = [[0 for i in range(cols)] for i in range(rows)]
    target_index = random.sample(range(rows*cols),N)
    for i in target_index:
        board[i/cols][i-i/cols*cols] = 9
    ## rearrange the board 
    board.append([0 for i in range(cols)])
    board.insert(0,[0 for i in range(cols)])
    for i in board:
        i.append(0)
        i.insert(0,0)

    for i in range(1,rows+1):
        for j in range(1,cols+1):
            if board[i][j] == 9:
                continue
            else:
                board[i][j] = count_mine(board,i,j)

    
    # shrink the board
    board.pop()
    del board[0]
    for i in board:
        i.pop()
        del i[0]

    for i in target_index:
        board[i/cols][i-i/cols*cols] = "x"

    return board
       
N = 10
rows = 10
cols  = 10

board = generate(N,rows,cols)
myprint(board)