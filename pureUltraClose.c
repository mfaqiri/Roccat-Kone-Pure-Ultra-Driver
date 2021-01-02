
static int close_mouse(struct inode *inode, struct file * file)
{

	if(--mouse_users)
		return 0;
	free_irq(konePure_IRQ, NULL);

	MOD_DEC_USE_COUNT;

	return 0;		




}
