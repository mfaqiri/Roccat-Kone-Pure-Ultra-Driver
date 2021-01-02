
static unsigned int mouse_poll(struct file * file, poll_table *wait){

	poll_wait(file, &mouse_wait, wait);
	if(mouse_event)
		return POLLIN | POLLRDNORM;
	return 0;


}
