class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> k;

        for(int i = 0; i < nums.size(); i++) {

            int j;

            for(j = i + 1; j < nums.size(); j++) {

                if(nums[j] > nums[i]) {
                    k.push_back(nums[j]);
                    break;
                }
            }

            if(j == nums.size()) {

                int r;

                for(r = 0; r < i; r++) {

                    if(nums[r] > nums[i]) {
                        k.push_back(nums[r]);
                        break;
                    }
                }

                if(r == i) {
                    k.push_back(-1);
                }
            }
        }

        return k;
    }
};


/*
====================================================================
PSEUDOCODE
====================================================================

For every element nums[i]:

    Search to the right of i.

    If a greater element is found:
        push it into k
        stop searching

    If nothing is found on the right:
        search from the beginning of the array

        If a greater element is found:
            push it into k

        Otherwise:
            push -1


====================================================================
APPROACH
====================================================================

This is a BRUTE-FORCE approach for the circular array.

For each nums[i], we divide the search into two parts:

1. RIGHT SEARCH:
       i+1 → end

2. CIRCULAR SEARCH:
       0 → i-1

Together these cover everything that comes after nums[i]
when the array is considered circular.


Example:

nums = [1, 2, 3, 4, 3]
                    ↑
                    i

First search:

                    i
                    ↓
[1, 2, 3, 4, 3]
             ↑
             search to the right

If nothing is found, wrap around:

[1, 2, 3, 4, 3]
 ↑           ↑
start        i

Search from 0 to i-1.


====================================================================
WHAT EACH VARIABLE MEANS
====================================================================

i = the current element we are solving.

j = used to search to the RIGHT of i.

r = used to search from the BEGINNING after wrapping around.

So remember:

    i → current element
    j → right search
    r → circular/wrap search


====================================================================
WHY IS j DECLARED OUTSIDE THE LOOP?
====================================================================

We write:

    int j;

    for(j = i + 1; j < nums.size(); j++)

instead of:

    for(int j = i + 1; j < nums.size(); j++)

because we need to use j AFTER the loop:

    if(j == nums.size())

j tells us HOW the loop ended.

If:

    j != nums.size()

then the loop stopped because of:

    break;

which means we FOUND a greater element.

If:

    j == nums.size()

then the loop reached the end naturally.

That means:

    NOTHING greater was found on the right.


====================================================================
WHY CAN'T WE CHECK j == nums.size() INSIDE THE LOOP?
====================================================================

The loop is:

    for(j = i + 1; j < nums.size(); j++)

The loop only runs while:

    j < nums.size()

When j becomes:

    j == nums.size()

the loop condition becomes false.

Therefore the loop stops BEFORE executing its body.

So this check must be AFTER the loop:

    if(j == nums.size())


====================================================================
WHY DO WE NEED THE SECOND SEARCH?
====================================================================

Because this is a CIRCULAR array.

Example:

    nums = [1, 2, 3, 4, 3]
                        ↑
                        i

There is nothing after the last 3.

But circularly, after the last element we come back to:

    1 → 2 → 3 → 4

So we search from index 0.


====================================================================
WHY IS THE r LOOP r < i?
====================================================================

The first loop already checked:

    i+1 → end

Therefore after wrapping, we only need:

    0 → i-1

We don't check nums[i] again because that is the
original element itself.

Therefore:

    for(r = 0; r < i; r++)


====================================================================
WHY DO WE DECLARE r OUTSIDE ITS LOOP?
====================================================================

Same reason as j.

We need to check r AFTER the loop:

    if(r == i)

If we wrote:

    for(int r = 0; r < i; r++)

then r would only exist inside that loop.

By writing:

    int r;

    for(r = 0; r < i; r++)

we can use r afterward.


====================================================================
WHY DOES r == i MEAN "NO ANSWER"?
====================================================================

The loop is:

    for(r = 0; r < i; r++)

If a greater element is found:

    break;

So r stops before reaching i.

Example:

    i = 4

If greater element is found at r = 2:

    r = 2
    r != i

But if nothing is found:

    r = 0
    r = 1
    r = 2
    r = 3
    r = 4

Now:

    r == i

Therefore:

    k.push_back(-1);


====================================================================
WHY CAN'T WE PUT -1 INSIDE THE LOOP?
====================================================================

WRONG:

    for(r = 0; r < i; r++) {

        if(nums[r] > nums[i]) {
            k.push_back(nums[r]);
            break;
        }
        else {
            k.push_back(-1);
        }
    }

Why wrong?

Because one failed comparison does NOT mean
the entire search failed.

Example:

    nums = [1, 2, 3, 4, 3]
                        ↑
                        i

First circular check:

    1 > 3 → NO

But we still have:

    2 > 3 → NO
    3 > 3 → NO
    4 > 3 → YES

Therefore -1 can only be added AFTER the COMPLETE
search has finished.


====================================================================
WHY IS THERE NO ELSE AFTER if(j == nums.size())?
====================================================================

We have:

    if(j == nums.size()) {
        // nothing found on right
        // do circular search
    }

If j is NOT equal to nums.size(), that means:

    a greater element WAS found.

And we already did:

    k.push_back(nums[j]);

Therefore we should NOT push -1.

So:

    j == nums.size()
        → right search failed
        → circular search

    j != nums.size()
        → answer already found
        → do nothing


====================================================================
WHY nums[r] > nums[i]?
====================================================================

During the circular search, i is still the original
element we are solving.

So we ask:

    Is nums[r] greater than nums[i]?

NOT:

    nums[r] > nums[j]

because when j == nums.size():

    nums[j]

would be outside the valid array indexes.


====================================================================
WHY DO WE USE break?
====================================================================

The problem asks for the FIRST greater element.

Example:

    [1, 3, 4, 5]

For 1:

    3 > 1 → YES

3 is the answer.

We DON'T continue to 4 or 5.

Therefore:

    k.push_back(nums[j]);
    break;

The same idea applies to the circular search.


====================================================================
WHY IS nums[j] THE ANSWER?
====================================================================

j moves from left to right:

    i+1
    i+2
    i+3
    ...

Therefore the FIRST time:

    nums[j] > nums[i]

is true, nums[j] is automatically the
NEXT GREATER element.


====================================================================
WHY k IS A VECTOR
====================================================================

We need one answer for every element in nums.

Therefore:

    nums.size() = number of elements

and eventually:

    k.size() = nums.size()

Each element gets either:

    greater element

or:

    -1


====================================================================
IMPORTANT COMPILER/LOOP LESSON WE LEARNED
====================================================================

A variable declared inside a loop has limited SCOPE.

For example:

    for(int j = 0; ...)

j belongs to that loop.

You cannot reliably use it afterward.

If you need it afterward:

    int j;

    for(j = 0; ...)

This is why we declared j and r outside their loops.


====================================================================
FINAL MENTAL MODEL
====================================================================

             nums[i]
                 |
                 ↓
        Search RIGHT using j
                 |
          +------+------+
          |             |
        FOUND         NOT FOUND
          |             |
          ↓             ↓
       push it      j == nums.size()
                        |
                        ↓
                  Wrap using r
                        |
                 +------+------+
                 |             |
               FOUND        NOT FOUND
                 |             |
                 ↓             ↓
              push it         -1


Remember:

    i = current element
    j = right search
    r = wrap search

    j == nums.size()
        = nothing found on right

    r == i
        = nothing found after wrapping

    break
        = first greater element found

    -1
        = only after ALL possible positions were checked


====================================================================
IMPORTANT: YOUR APPROACH
====================================================================

This is your BRUTE-FORCE approach.

You are not using a stack.

You are manually:

    1. Searching right
    2. Wrapping around if necessary
    3. Searching the beginning
    4. Returning -1 if both searches fail

The optimized solution uses a MONOTONIC STACK,
but understanding this brute-force version first is
completely fine.
====================================================================
*/