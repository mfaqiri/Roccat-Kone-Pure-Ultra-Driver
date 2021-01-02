#define KONEPUREULTRA_BASE 0x300

static struct miscdevice pureUltra = {
KONEPUREULTRA_MINOR, "ROCCAT kone pure ultra", &pureUltra_fops
};

__init pureUltra_init(void)
{
if(check_region(KONEPUREULTRA_BASE, 3))
	return -ENODEV;

request_region(KONEPUREULTRA_BASE,3,"ROCCAT kone pure ultra");

misc_register(&pureUltra);
return 0;
}
