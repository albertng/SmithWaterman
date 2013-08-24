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
    print("Usage: python nt2twobit.py <NT FILENAME> <OUT FILENAME> <IS REFERENCE>")
    sys.exit(0)

nt_filename = sys.argv[1]
out_filename = sys.argv[2]
is_ref = sys.argv[3]

nt_seq = open(nt_filename, 'r').readlines()[0].strip()
out_file = open(out_filename, 'wb')
for i in range(len(nt_seq)/4):
    nt_block_hex = 0
    if (is_ref == '0'):
        for j in range((i*4), (i*4)+4):
            nt_block_hex <<= 2
            nt_block_hex += nt2twobit(nt_seq[j])
        out_file.write("%c" % (nt_block_hex))
    else:
        for j in range((i*4)+3, i*4-1, -1):
            nt_block_hex <<= 2
            nt_block_hex += nt2twobit(nt_seq[j])
        out_file.write("%c" % (nt_block_hex))
out_file.close()

