struct file_operations pureUltra_fops = {

	 NULL,        /* Mice don't seek */

	read_mouse,  /* You can read a mouse */

	write_mouse, /* This won't do a lot */

	NULL,        /* No readdir - not a directory */

	poll_mouse,  /* Poll */

	NULL,        /* No ioctl calls */

        NULL,        /* No mmap */

	open_mouse,  /* Called on open */

	NULL,        /* Flush - 2.2 only */

	close_mouse, /* Called on close */

	NULL,        /* No media change on a mouse */

	NULL,        /* Asynchronous I/O - we will add this later*/



};
