import random
import sys

def __main__ ():
	
	max_frame = sys.argv[1]
	out_file = open (sys.argv[2],'w')

	for x in range(0,int(max_frame)):

		frame = '01010000'

		for y in xrange(0,120):
			frame += random.choice('01') #picks 0 or 1 sudo-randomly

		out_file.write(frame + '\n')

		if (x % 1000000 == 0):
			print x / 1000000, ' mill'

	out_file.close()

if __name__ == "__main__":
	__main__()




