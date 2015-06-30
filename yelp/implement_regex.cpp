bool ismatch(string s,string p){
    if (s == null || p == null) {
        return false;
    }

    // bug 2: should use boolean instead of int.
    boolean[][] D = new bool[s.size() + 1][p.size() + 1];
    // D[i][j]: i, j, the length of String s and String p.        
    for (int i = 0; i <= s.length(); i++) {
        for (int j = 0; j <= p.length(); j++) {
            if (j == 0) {
                // when p is empth, the s should be empty.
                D[i][j] = i == 0;
            } else if (p.charAt(j - 1) == '*') {
                /*
                    P has at least one node.
                */
                
                // The last node in p is '*'
                if (j < 2) {
                    // a error: there should be a character before *.
                    //return false;
                }
                
                // we can match 0 characters or match more characters.
                for (int k = 0; k <= i; k++) {
                    // BUG 3: severe! Forget to deal with the empty string!!
                    if (k != 0 && !isSame(s.charAt(i - k), p.charAt(j - 2))) {
                        D[i][j] = false;
                        break;
                    }
                    
                    if (D[i - k][j - 2]) {
                        D[i][j] = true;
                        break;
                    }
                }
            } else {
                D[i][j] = i >= 1 
                     && isSame(s.charAt(i - 1), p.charAt(j - 1))
                     && D[i - 1][j - 1];
            }
        }
    }
    return D[s.length()][p.length()];
}