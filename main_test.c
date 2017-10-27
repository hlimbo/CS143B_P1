#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "code/io_system.h"
#include "code/file_system.h"

#define FREE -1

int main(int argc,char* argv[])
{

//	printf("logical blocks: %d\n",LOGICAL_BLOCKS);
//	printf("bytes per block: %d\n\n",BYTES_PER_BLOCK);
//	printf("disk blocks count: %d\n", DISK_BLOCKS_COUNT);
//	printf("fd capacity: %d\n",FD_CAPACITY);
//	printf("ints per block: %d\n",INTS_PER_BLOCK);
//	printf("fds_per_block: %d\n",FDS_PER_BLOCK);
//	printf("dir blocks: %d\n",DIR_BLOCKS);
//	printf("dir entry capacity: %d\n",DIR_ENTRY_CAPACITY);
//
//	printf("MAX DIR ENTRIES: %d\n",MAX_DIR_ENTRIES);
//	printf("DIR ENTRIES PER BLOCK: %d\n",DIR_ENTRIES_PER_BLOCK);
//	printf("\n reserved bitmap blocks: %d\n",RESERVED_BITMAP_BLOCKS);
//	printf("reserved fd blocks: %d\n",RESERVED_FD_BLOCKS);
//	printf("reserved blocks: %d\n\n",RESERVED_BLOCKS);
//
//	printf("OFT_SIZE: %d\n",OFT_SIZE);
	

	//file_system.init(NULL);
	file_system.init(argv[1]);
	print_bitmap();
	print_blocks();
	
	file_system.create("abc");
	print_bitmap();
	print_blocks();
	
	char directory_metadata[B];
	io_system.read_block(1,directory_metadata);
	
//	file_system.destroy("abc");
//	print_bitmap();
//	print_blocks();
		

	//goal is to grab the directory datablocks to see the actual contents of each directory entry listing

	file_descriptor dir_fd = GetFD(1,0);
	printf("file_len: %d\n",dir_fd.file_len);
	for(int i = 0;i < DISK_BLOCKS_COUNT;++i)
		printf("block: %d\n",dir_fd.block_numbers[i]);	



	file_system.save(argv[1]);

	return 0;
}
