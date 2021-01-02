#ifdef MODULE

int init_module(void)
{
	if(purUltra_init()<0)
		return -ENODEV;
	return 0;

}

void cleanup_module(void){

	misc_deregister(&our_mouse);
	free_region(KONEPUREULTRA_BASE,3);


}

#endif
