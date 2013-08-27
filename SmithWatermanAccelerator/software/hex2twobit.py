import sys

if len(sys.argv) < 3:
    print("Usage: python hex2twobit.py <HEX FILENAME> <OUT FILENAME>")
    sys.exit(0)

hex_filename = sys.argv[1]
out_filename = sys.argv[2]

hex_seq = open(hex_filename, 'r').readlines()[0].strip()
print(hex_seq)
out_file = open(out_filename, 'wb')
for i in range(len(hex_seq)-1, 0, -2):
    print(hex_seq[i-1:i+1])
    byte = int(hex_seq[i-1:i+1], 16)
    out_file.write("%c" % (byte))
out_file.close()
