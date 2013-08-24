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

if len(sys.argv) < 4:
    print("Usage: python nt2hex.py <NT FILENAME> <OUT FILENAME> <BLOCK SIZE>")
    sys.exit(0)

nt_filename = sys.argv[1]
out_filename = sys.argv[2]
block_size = int(sys.argv[3])

nt_seq = open(nt_filename, 'r').readlines()[0].strip()
out_file = open(out_filename, 'w')

# For each block in the sequence
for block in range(len(nt_seq)/block_size):
    # For each byte in the block
    for byte in range(block_size/4 - 1, -1, -1):
        hex_val = (nt2twobit(nt_seq[block*block_size + byte*4 + 3]) << 2) + (nt2twobit(nt_seq[block*block_size + byte*4 + 2]))
        out_file.write(hex(hex_val)[-1])
        hex_val = (nt2twobit(nt_seq[block*block_size + byte*4 + 1]) << 2) + (nt2twobit(nt_seq[block*block_size + byte*4]))
        out_file.write(hex(hex_val)[-1])
    out_file.write('\n')
out_file.close() 


