import sys
import math

# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.

n = int(input())  # Number of elements which make up the association table.
q = int(input())  # Number Q of file names to be analyzed.
dict = {}
for i in range(n):
	# ext: file extension
	# mt: MIME type.
	ext, mt = input().split()
	dict[ext.lower()] = mt
#print(dict)
for i in range(q):
	fname = input()	 # One file name per line.
	fname = fname.lower()
	#print(fname[fname.rfind('.'):len(fname)])
	#print(dict[fname[fname.rfind('.'):len(fname)]])
	pointnum = fname.rfind('.')
	if pointnum != -1:
		if fname[pointnum + 1:len(fname)] in dict.keys():
			print(dict[fname[fname.rfind('.') + 1:len(fname)]])
		else:
			print('UNKNOWN')
	else:
		print('UNKNOWN')
	



# Write an action using print
# To debug: print("Debug messages...", file=sys.stderr)


# For each of the Q filenames, display on a line the corresponding MIME type. If there is no corresponding type, then display UNKNOWN.
#print("UNKNOWN")
