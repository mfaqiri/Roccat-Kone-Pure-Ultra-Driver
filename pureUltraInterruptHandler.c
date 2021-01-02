static struct wait_queue *mouse_wait;
static spinlock_t mouse_lock = SPIN_LOCK_UNLOCKED;

static void pureUltra_interrupt(int irq, void *dev_id, struct pt_regs * regs){
char delta_x;
char delta_y;
unsigned char new_buttons;

if(delta_x || delta_y || new_buttons != mouse_buttons){

	spin_lock(&mouse_lock);
	mouse_event = 1;
	mouse_dx += delta_x;
	mouse_dy += delta_y;
	mouse_buttons = new_buttons;
	spin_unlock(&mouse_lock);

	wake_up_interruptible(&mouse_wait);

}



}
