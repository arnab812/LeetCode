var myAtoi = function(str) {
    
    // Use JS built in method to remove spaces
    // Check if string's length is more than 0
    str = str.trim();
    const length = str.length;
    if (length === 0 ) return 0;
    
    // Assign MIN and MAX ranges, from description
    const min = Math.pow(-2, 31);
    const max = Math.pow(2, 31) -1;
    
    // Create variables
    let i = 0;
    let result = "";
    let isNegative = false;
    
    // Check if first sign is + or -
    // If sign is -, change isNegative value to true
    // Increase i, since we already checked first (0) index
    if (str[i] === '+' || str[i] === '-') {
        isNegative = str[i] === '-' ? true : false;
        i = 1;
    }
    
    // Go through remaining string, get char code of each character
    // Number 0 to 9 characters are 48 to 57, so we minus 48 to get exact number
    // If that's a number between 0 and 9, add it to our result, otherwise stop this loop
    for (i; i < length; i++) {
        const temp = str.charCodeAt(i) - 48;
        if (temp < 0 || temp > 9)
            break;
        else
            result += str[i];
    }
    
    // If we had - in front of our number, change it to negative
    result = (isNegative === true) ? -result : result;
    
    // Check if our result is in range
    if (result < min) return min;
    if (result > max) return max;
    
    return result;
}
