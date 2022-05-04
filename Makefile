all : app dox

app :
	cd src; make all

dox :
	cd Doxygen; doxygen; ln -s -r ./html/index.html ../DOCUMENTATION

clean :
	cd src; make clean; cd ..;rm -f HLM63; rm -r -f Doxygen/html; rm -f ./DOCUMENTATION
