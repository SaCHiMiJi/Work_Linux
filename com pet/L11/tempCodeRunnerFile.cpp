// <= up
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j]) 
            return false;
    
    // => up
    for (i = row, j = col; i >= 0 && j < N; i--, j++)
        if (board[i][j]) 
            return false;
    
    // <= down
    for (i = row, j = col; j >= 0 && i < N; i++, j--)
         if (board[i][j]) 
            return false;
    
    // => down
    for (i = row, j = col; j < N && i < N; i++, j++)
        if (board[i][j]) 
            return false;
