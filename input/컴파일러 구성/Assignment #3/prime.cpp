/*
    Mini C has two types of comments: text comment and line comment.
*/

/*
   A palindromic number is unchanged if its digits are reversed.
   121 or 1221 is a palindrome.
*/

const int max = 100;
void main()
{
    int i, j, k;
    int rem, prime;	// rem : remainder

    i = 2;
    while (i <= max) {
        prime = 1;
        k = i / 2;
        j = 2;
        while (j <= k) {
            rem = i % j;
            if (rem == 0) prime = 0;
            ++j;
        }
        if (prime == 1) write(i);
        ++i;
    }
}

//Assignment #3

// 컴파일러 구성 prime.mc