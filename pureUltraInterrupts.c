
static int mouse_users = 0, mouse_dx = 0, mouse_dy = 0, mouse_event = 0;

static int open_mouse(struct inode * inode, struct file *file)
{
	if(mouse_users++)
		return 0;
	if(request_irq(mouse_intr, pureUltra_IRQ, 0, "ROCCAT kone pure ultra", NULL)){
		mouse_users--;
		return -EBUSY;
	}

	mouse_dx = 0;
	mouse_dy = 0;
	mouse_buttons = 0;
	mouse_event = 0;
	MOD_INC_USE_COUNT;

}
