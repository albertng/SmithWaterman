def Max(values):
    max = float("-inf")
    for val in values:
        if val > max:
            max = val
    return max

def SmithWaterman(short_read, reference):
    # Scoring Scheme
    match = 2
    mismatch = -2
    gap_open = -2
    gap_extend = -1

    max_score = 0
    max_row = 0
    max_col = 0
    V = [[0] * (len(short_read) + 1) for i in range(len(reference) + 1)]
    E = [[0] * (len(short_read) + 1) for i in range(len(reference) + 1)]
    F = [[0] * (len(short_read) + 1) for i in range(len(reference) + 1)]
    V_dir = [['Z'] * (len(short_read) + 1) for i in range(len(reference) + 1)]
    for i in range(1, len(V)):
        for j in range(1, len(V[i])):
            E[i][j] = Max([V[i][j-1] + gap_open, E[i][j-1] + gap_extend])
            F[i][j] = Max([V[i-1][j] + gap_open, F[i-1][j] + gap_extend])
            
            if short_read[j-1] == 'N' or reference[i-1] == 'N':
                match_score = -1
            elif short_read[j-1] == reference[i-1]:
                match_score = V[i-1][j-1] + match
            else:
                match_score = V[i-1][j-1] + mismatch
            V[i][j] = Max([0, E[i][j], F[i][j], match_score])
            if (V[i][j] == 0):
                V_dir[i][j] = 'Z'
            elif (V[i][j] == E[i][j]):
                V_dir[i][j] = 'I'
            elif (V[i][j] == F[i][j]): 
                V_dir[i][j] = 'D'
            else:
                V_dir[i][j] = 'M'
            if V[i][j] > max_score:
                max_score = V[i][j]
                max_row = i
                max_col = j
    print 'V:'
    for row in range(len(V)):
        for col in range(len(V[0])):
            print(str(V[row][col]) + '\t'),
        print ''
    print ''
    print 'V_dir:'
    for row in range(len(V_dir)):
        for col in range(len(V[0])):
            print(str(V_dir[row][col]) + '\t'),
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
    return (max_score, max_row, max_col, V_dir)

#ref = "AGAAAGTCA"
#query = "GGTCAG"
ref ="AGCTAGTCNNGTTTGAACCGAGTCGATCGACTAGCGCCATCTANNCTAGCTAGCTATNCGATCG"
#query = "AGCTAGTCNN"
#query = "GACCGAGACT"
#query = "TAACCTAGCTAGCT"
#query = "CCATGTATCG"
query = "TATNCATGG"
(max_score, max_row, max_col, V_dir) = SmithWaterman(ref, query)
print(max_score)

# Perform Traceback
aln1 = ""
aln2 = ""
row = max_row
col = max_col
decisions = ""
while (V_dir[row][col] != 'Z'):
    print(row, col)
    decisions = V_dir[row][col] + decisions
    if (V_dir[row][col] == 'M'):
        aln1 = ref[col-1] + aln1
        aln2 = query[row-1] + aln2
        row -= 1
        col -= 1
    elif (V_dir[row][col] == 'I'):
        aln1 = ref[col-1] + aln1
        aln2 = "-" + aln2
        col -= 1
    elif (V_dir[row][col] == 'D'):
        aln1 = "-" + aln1
        aln2 = query[row-1] + aln2
        row -= 1
print(aln1)
print(aln2)
print(decisions)
