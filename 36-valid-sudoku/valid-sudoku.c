bool isValidSudoku(char** board, int boardSize, int* boardColSize){
    int row[9][9] = {0};
    int col[9][9] = {0};
    int box[9][9] = {0};
    
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(board[i][j] == '.')
                continue;
            
            int num = board[i][j] - '1';   // convert '1'-'9' to 0-8
            int boxIndex = (i / 3) * 3 + (j / 3);
            
            if(row[i][num] || col[j][num] || box[boxIndex][num])
                return false;
            
            row[i][num] = col[j][num] = box[boxIndex][num] = 1;
        }
    }
    return true;
}
