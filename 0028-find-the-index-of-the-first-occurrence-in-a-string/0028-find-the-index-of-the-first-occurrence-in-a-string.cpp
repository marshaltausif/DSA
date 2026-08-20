class Solution {
public:
    int strStr(string haystack, string needle) {
        string ans;

        for (int i = 0; i < haystack.size(); i++) {

            ans = "";

            for (int j = 0; j < needle.size(); j++) {

                if (i + j < haystack.size() &&
                    needle[j] == haystack[i + j]) {

                    ans += needle[j];

                    if (ans == needle) {
                        return i;
                    }
                }
                else {
                    break;
                }
            }
        }

        return -1;
    }
};


/*
======================== APPROACH / PSEUDOCODE ========================

1. Take every index i in haystack as a possible starting position.

2. For every new i:
       reset ans = ""

   because every i is a fresh attempt.

3. Use j to move through needle.

4. Compare:
       needle[j] == haystack[i + j]

   i     = starting position in haystack
   j     = how far we have moved from that starting position
   i+j   = current position in haystack

5. If the characters match:
       add needle[j] to ans.

6. If:
       ans == needle

   the complete needle has been found,
   so return i.

7. If there is a mismatch:
       break

   because this particular i cannot be the answer.
   Move to the next i and try again.

8. If all possible i values are checked and no complete
   match is found:
       return -1.


======================== WHY i + j? ========================

Example:

haystack = "xxcatxx"
needle   = "cat"

i = 2

j = 0:
i+j = 2
needle[0] == haystack[2]
c == c

j = 1:
i+j = 3
needle[1] == haystack[3]
a == a

j = 2:
i+j = 4
needle[2] == haystack[4]
t == t


i = WHERE THE MATCH STARTS
j = HOW FAR WE HAVE MOVED
i+j = CURRENT POSITION IN HAYSTACK


======================== WHY NOT haystack[i]? ========================

If we used:

    needle[j] == haystack[i]

then i stays fixed during the inner loop.

For i = 2:

    needle[0] → haystack[2]   c == c ✓
    needle[1] → haystack[2]   a == c ✗
    needle[2] → haystack[2]   t == c ✗

We keep checking the SAME character.

Using i+j:

    needle[0] → haystack[2]
    needle[1] → haystack[3]
    needle[2] → haystack[4]

So both strings move together.


======================== WHY ans = ""? ========================

ans = "" means RESET ans to an empty string.

It must happen inside the outer i loop because every
starting position is a new attempt.

Example:

i = 0 → ans = "" → try
i = 1 → ans = "" → fresh try
i = 2 → ans = "" → fresh try


If ans = "" were inside the j loop, it would reset
every time j changes:

j = 0 → ans = "" → "c"
j = 1 → ans = "" → "a"
j = 2 → ans = "" → "t"

Then ans can NEVER become "cat".


======================== WHY RETURN i? ========================

We don't need a separate start variable.

The outer loop checks:

    i = 0
    i = 1
    i = 2
    i = 3
    ...

Therefore, the first time:

    ans == needle

is true, that i is automatically the FIRST occurrence.

So:

    return i;

is enough.


======================== WHY break? ========================

If even one character doesn't match, that starting position i
cannot contain the complete needle.

So:

    mismatch → break → next i

We don't need to waste time checking the remaining characters.


======================== FINAL MEMORY TRICK ========================

i     = WHERE DO I START?
j     = HOW FAR HAVE I MOVED?
i + j = WHERE AM I NOW?

ans = ""       → fresh attempt
ans += char    → build the match
ans == needle  → complete match → return i
mismatch       → break
nothing found  → return -1

======================================================================
*/