public int myAtoi(String s) {
        char[] letters = s.trim().toCharArray();
        if (letters.length == 0) return 0;
        long num = 0;
        int idx = letters[0] == '-' || letters[0] == '+' ? 1 : 0;
        while (idx < letters.length && Character.isDigit(letters[idx]) && num < Integer.MAX_VALUE) {
            num = num * 10 + (letters[idx++] - '0');
        }
        
        if (letters[0] == '-') {
            num = -num;
            if (num < Integer.MIN_VALUE) return Integer.MIN_VALUE;
        } else {
            if (num > Integer.MAX_VALUE) return Integer.MAX_VALUE;
        }
        return (int) num;
    }
