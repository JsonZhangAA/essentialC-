   import sys
   import os
   import struct
   import random
   infile=file(sys.argv[1],"rb")
   s=struct.Struct('@IIf')
   #for line in infile:
   count=0;
   length_file=os.path.getsize(sys.argv[1])
   print length_file
       #print infile
   length_file=100
   while count<length_file:
       src,dst,value=s.unpack(infile.read(12));
       count=count+12
       print str(src)+"->"+str(dst)+":"+str(value)+"\n"
  print count/12
  infile.close