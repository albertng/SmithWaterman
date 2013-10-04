def Max(values):
    max = float("-inf")
    for val in values:
        if val > max:
            max = val
    return max

def SmithWaterman(short_read, reference):
    # Scoring Scheme
    match = 10
    mismatch = -2
    gap_open = -2
    gap_extend = -1

    max_score = 0
    V = [[0] * (len(short_read) + 1) for i in range(len(reference) + 1)]
    E = [[0] * (len(short_read) + 1) for i in range(len(reference) + 1)]
    F = [[0] * (len(short_read) + 1) for i in range(len(reference) + 1)]
    for i in range(1, len(V)):
        for j in range(1, len(V[i])):
            E[i][j] = Max([V[i][j-1] + gap_open, E[i][j-1] + gap_extend])
            F[i][j] = Max([V[i-1][j] + gap_open, F[i-1][j] + gap_extend])
            
            if short_read[j-1] == reference[i-1]:
                match_score = V[i-1][j-1] + match
            else:
                match_score = V[i-1][j-1] + mismatch
            V[i][j] = Max([0, E[i][j], F[i][j], match_score])
            if V[i][j] > max_score:
                max_score = V[i][j]
     
    print 'V:'
    for row in range(len(V)):
        for col in range(len(V[0])):
            print(str(V[row][col]) + '\t'),
        print ''
    print ''
    print 'E:'
    for row in range(len(E)):
        for col in range(len(E[0])):
            print(str(E[row][col]) + '\t'),
        print ''
    print ''
    print 'F:'
    for row in range(len(F)):
        for col in range(len(F[0])):
            print(str(F[row][col]) + '\t'),
        print ''
    print ''
    return max_score

#print(SmithWaterman("ACAGACTA", "AGCACACA"))
print(SmithWaterman("ACAGACTA", "ACACTA"))
