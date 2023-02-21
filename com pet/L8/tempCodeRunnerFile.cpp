if (lazy[node] != 0)
    {                             // This node needs to be updated
        tree[node] += lazy[node]; // Update it
        if (a != b)
        { // Mark child as lazy
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0; // Reset it
    }