static ssize_t mouse_read(struct file * file, char *buffer, size_t count, loff_t *pos){
	int dx, dy, n;
	unsigned char button;
	unsigned long flags;

	
	if(count < 3)
		return -EINVAL;

	while(!mouse_event){
		if(file->f_flags&O_NDELAY)
			return -EAGAIN;
		interruptable_sleep_on(&mouse_wait);
		if(signal_pending(current))
			return -ERESTARTSYS;



	}

	spin_lock_irqsave(&mouse_lock,flags);

	dx = mouse_dx;
	dy = mouse_dy;
	button = mouse_buttons;

	if(dx <= -127)
		dx = -127;
	if(dx >= 127)
		dx = 127;
	if(dy <= -127)
		dy = -127;
	if(dy >= 127)
		dy = 127;

	mouse_dx -= dx;
	mouse_dy -= dy;

	if(mouse_dx == 0 && mouse_dy == 0)
		mouse_event = 0;

	spin_unlock_irqrestore(&mouse_lock,flags);

	if(put_user(button|0x80, buffer))
		return -EFAULT;
	if(put_user((char)dx, buffer+1))
		return -EFAULT;
	if(put_user((char)dy, buffer+2))
		return -EFAULT;

	for(n=3, n < count, n++)
		if(put_user(0x00, buffer+n))
			return -EFAULT;
	return count;

}
