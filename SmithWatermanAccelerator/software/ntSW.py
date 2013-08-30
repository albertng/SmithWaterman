import sys

def Max(values):
    max = float("-inf")
    for val in values:
        if val > max:
            max = val
    return max

def SmithWaterman(seq1, seq2):
    # Scoring Scheme
    match = 2
    mismatch = -2
    gap_open = -2
    gap_extend = -1

    max_score = 0
    V = [[0] * (len(seq1) + 1) for i in range(len(seq2) + 1)]
    E = [[0] * (len(seq1) + 1) for i in range(len(seq2) + 1)]
    F = [[0] * (len(seq1) + 1) for i in range(len(seq2) + 1)]
    for i in range(1, len(V)):
        for j in range(1, len(V[i])):
            E[i][j] = Max([V[i][j-1] + gap_open, E[i][j-1] + gap_extend])
            F[i][j] = Max([V[i-1][j] + gap_open, F[i-1][j] + gap_extend])

            if seq1[j-1] == seq2[i-1]:
                match_score = V[i-1][j-1] + match
            else:
                match_score = V[i-1][j-1] + mismatch
            V[i][j] = Max([0, E[i][j], F[i][j], match_score])
            if V[i][j] > max_score:
                max_score = V[i][j]

    return max_score

# Note: END COORD is last bp coord + 1
if len(sys.argv) < 5:
    print("Usage: python ntSW.py <REF SEQ FILE> <START COORD> <END COORD> <QUERY SEQ FILE>")
    sys.exit(0)

ref_filename = sys.argv[1]
start_coord = int(sys.argv[2])
end_coord = int(sys.argv[3])
query_filename = sys.argv[4]

ref_seq = open(ref_filename, 'r').readlines()[0].strip()
query_seq = open(query_filename, 'r').readlines()[0].strip()

print(SmithWaterman(ref_seq[start_coord:end_coord], query_seq))
