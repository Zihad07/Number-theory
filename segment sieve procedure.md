Segmented Sieve of Eratosthenes
Problem
Given two integers A and B, find number of primes inside the range of A and B inclusive. Here, 1≤A≤B≤1012 and B−A≤105.

For example, A=11 and B=19, then answer is 4 since there are 4 primes within that range (11,13,17,19).

If limits of A and B were small enough ( ≤108 ), then we could solve this problem using the ordinary sieve. But here limits are huge, so we don't have enough memory or time to run normal sieve. But note that, B−A≤105. So even though we don't have memory/time to run sieve from 1 to N, we have enough memory/time to cover A to B.

A to B is a segment, and we are going to modify our algorithm for Sieve of Eratosthenes to cover this segment. Hence, the modified algorithm is called Segmented Sieve of Eratosthenes. 

Make sure you fully understand how "Normal" Sieve of Eratosthenes works.

How Normal Sieve Works
First, let us see the steps for "Normal" sieve. In order to make things simpler, we will be looking into a somewhat unoptimized sieve. You can implement your own optimizations later.

Suppose we want to find all primes between 1 to N.
First we define a new variable sqrtn=N−−√.
We take all primes less than sqrtn. 
For each prime p, we repeat the following steps.
We start from j=p×p.
If j≤N, we mark sieve at position j to be not prime.
Else, we break out of the loop.
We increase the value of j by p. And go back to step step 2 of this loop.
All positions in the sieve that are not marked are prime.
This is how the basic sieve works. We will now modify it to work on segments.

How Segmented Sieve Works
We will perform the same steps as normal sieve but just slightly modified.

Generate Primes Less Than N−−√
In the segmented sieve, what is he largest limit possible? 1012. So let N=1012

First of all, in the normal sieve we worked with primes less than N−−√ only. So, if we had to run sieve from 1 to N, we would have required only primes less than N−−√=106. So in order to run sieve on a segment between 1 to N, we won't require primes greater than N−−√.

So, using normal sieve we will first generate all primes less than N−−√=106.

Run on Segment
Okay, now we can start our "Segmented" Sieve. We want to find primes between A and B. 
If A is equal to 1, then increase A by 1. That is, make A=2. Since 1 is not a prime, this does not change our answer.
Define a new variable sqrtn=B−−√.
Declare a new array of size dif=maximum difference of (B−A)+1. Since it is given in our problem that B−A≤105, dif=105+1 for this problem. 

Let the array be called arr. This array has index from 0 to dif−1. Here arr[0] represents the number A, arr[1] represents A+1 and so on.
Now, we will be working with all primes less than sqrtn. These primes are already generated using the normal sieve.
For each prime p, we will repeat the following steps:
We start from j=p×p.
But initial value of j=p2 might be less than A. We want to mark positions between A and B only. So we will need to shift j inside the segment.

So, if j<A, then j=ceil(Ap)×p=A+p−1p×p. This line makes j the smallest multiple of p which is bigger than A.
If j≤B, we mark sieve at position j to be not prime.
Else, we break out of the loop.

But when marking, remember that our array arr is shifted by A positions. arr[0] indicates position A of normal sieve. So, we will mark position j−A of arr as not prime.
Increase the value of j by p. Repeat loop from step 3.
All positions in arr which has not been marked are prime.
Step 1 is important. Since we only mark multiples of prime as not prime in the pseducode above, 1 which has no prime factor never gets marked. So we handle it by increassing value of A by 1 when A=1.

Code
If we convert the above pseducode into C++, then it becomes something like this:
int arr[SIZE];

///Returns number of primes between segment [a,b]
int segmentedSieve ( int a, int b ) {
    if ( a == 1 ) a++;

    int sqrtn = sqrt ( b );

    memset ( arr, 0, sizeof arr ); ///Make all index of arr 0.

    for ( int i = 0; i < prime.size() && prime[i] <= sqrtn; i++ ) {
        int p = prime[i];
        int j = p * p;

        ///If j is smaller than a, then shift it inside of segment [a,b]
        if ( j < a ) j = ( ( a + p - 1 ) / p ) * p;

        for ( ; j <= b; j += p ) {
            arr[j-a] = 1; ///mark them as not prime
        }
    }

    int res = 0;
    for ( int i = a; i <= b; i++ ) {
        ///If it is not marked, then it is a prime
        if ( arr[i-a] == 0 ) res++;
    }
    return res;
}
In line 1 we declare an array of SIZE. This array needs to be as large as maximum difference between B−A+1. Next in line 4 we declare a function that finds number of primes between a and b. Rest of the code is same as the psedocode above.

It is possible to optimize it further ( both for speed and memory ) but in expense of clarity. I am sure if readers understand the core concept behind this algorithm, then they will have no problem tweaking the code to suit their needs.
