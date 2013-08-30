# Converts a nucleotide character sequence to a binary file with 2-bit encoding
# Left-zero pads the last byte if sequence length not divisible by 4
# Example: ACGTCATGGATCTAGG = 36 C9 4B F8

import sys

def nt2twobit(nt):
    if nt == 'T':
      return 0
    if nt == 'C':
      return 1
    if nt == 'A':
      return 2
    if nt == 'G':
      return 3
    return 2

if len(sys.argv) < 4:
    print("Usage: python seq2twobit.py <SEQ FILENAME> <OUT FILENAME> <BLOCK SIZE>")
    sys.exit(0)
seq_filename = sys.argv[1]
out_filename = sys.argv[2]
block_size = int(sys.argv[3])
if block_size % 4 != 0:
    print("Block size must be multiple of 4!")
    sys.exit(0)

seq = open(seq_filename, 'r').readlines()[0].strip()

# Ensure sequence length is multiple of block size
if len(seq) % block_size != 0:
    for i in range(block_size - (len(seq) % block_size)):
        seq += 'N'

out_file = open(out_filename, 'wb')
for i in range(len(seq)/4):
    if (i % 2500000 == 0):
        print(i * 4)
    byte_hex = 0
    for j in range((i*4)+3, i*4-1, -1):
        byte_hex <<= 2
        byte_hex += nt2twobit(seq[j])
    out_file.write("%c" % (byte_hex))
out_file.close()    


'''block_size = 128
seqs = ['chr4', 'chr5', 'chr6', 'chr7', 'chr8', 'chr9', 'chr10', 'chr11', 'chr12', 'chr13', 'chr14', 'chr15', 'chr16', 'chr17', 'chr18', 'chr19', 'chr20', 'chr21', 'chr22', 'chrX', 'chrY']

for s in seqs:
    seq = open(s + '.seq', 'r').readlines()[0].strip()

    # Ensure sequence length is multiple of block size
    for i in range(len(seq) % block_size):
        seq += 'N'

    out_file = open(s + '.2bit', 'wb')
    for i in range(len(seq)/4):
        if (i % 2500000 == 0):
            print(s + ': ' + str(i * 4) + ' out of ' + str(len(seq)))
        byte_hex = 0
        for j in range((i*4)+3, i*4-1, -1):
            byte_hex <<= 2
            byte_hex += nt2twobit(seq[j])
        out_file.write("%c" % (byte_hex))
    out_file.close()    
'''
