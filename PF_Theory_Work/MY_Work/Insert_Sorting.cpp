




/*
Step-by-Step Example

    Array:

    [8, 3, 5, 2]

🟢 Step 1

    First element is always “sorted”:

    [8 | 3, 5, 2]

🟢 Step 2 – Insert 3

    Compare with 8:

    3 < 8 → shift 8 right

    Result:

    [3, 8 | 5, 2]

🟢 Step 3 – Insert 5

    Compare with 8 → shift
    Compare with 3 → stop

    Result:

    [3, 5, 8 | 2]

🟢 Step 4 – Insert 2

    Shift 8 → shift 5 → shift 3

    Result:

    [2, 3, 5, 8]


✅ Sorted.
*/