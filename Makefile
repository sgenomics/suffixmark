searchmark: 
	g++ -O3 searchmark.cpp ./suffixcore/SuffixNode.cpp ./suffixcore/SuffixNodeStoreMemVec.cpp ./suffixcore/tialloc/tialloc.cpp -o searchmark -I./suffixcore -I./suffixcore/tialloc -I./suffixtrans

searchmarkcur: SuffixTree.h Transcode.h ChildStore.h SuffixNode.h
	g++ -O3 searchmarkcur.cpp ./SuffixNode.cpp ./SuffixNodeStore.cpp ./tialloc.cpp -o searchmark

malmark: malmark.cpp tialloc.cpp tialloc.h
	g++ -O3 -march=native malmark.cpp tialloc.cpp -o malmark

clean:
	rm web
