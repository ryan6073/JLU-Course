#ifndef __KERNEL__
#define __KERNEL__
#endif

#ifndef MODULE
#define MODULE
#endif
#define __NO_VERSION__
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/version.h>
#include <linux/config.h>

#if CONFIG_MODVERSIONS == 1
#define MODVERSIONS
#include <linux/modversions.h>
#endif
#include <linux/fs.h>
#include <linux/types.h>
#include <asm/segment.h>
#ifndef KERNEL_VERSION
#define KERNEL_VERSION(a,b,c) ((a)*65536+(b)*256+(c))
#endif
/* Conditional compilation. LINUX_VERSION_CODE is
 * the code (as per KERNEL_VERSION) of this version.
*/
#if LINUX_VERSION_CODE > KERNEL_VERSION(2,2,0)
#include <asm/uaccess.h>  /* for put_user */
#include <stdio.h>
#include <sys/types.h>
#include <asm-generic/errno.h>
#endif
#define SUCCESS 0
#define DEVICE_NAME "kueng_char_dev"
#define BUF_LEN 50
static  int Device_Open =0;
static char Message[BUF_LEN];
static int Major;

static int mydev_open(struct inode *inode,struct file *file)
{
  if(Device_Open)
    return -EBUSY;
  Device_Open=1;
  MOD_INC_USE_COUNT;  // 模块使用者数加１，非0不能卸载
  return 0;
}
static int mydev_release(struct inode *inode,struct file *file)
{
  Device_Open=0;
  MOD_DEC_USE_COUNT;  // 模块使用者数减１
  return 0;
}
static ssize_t mydev_read(struct file *file,char *buffer, size_t length ,loff_t *f_pos)
{
  int bytes_read=0;
  //确认访问用户内存空间合法性
  if(verify_area(VERIFY_WRITE,buffer,length)==-EFAULT)
    return -EFAULT;
  //由用户空间到系统空间复制
  bytes_read=copy_to_user(buffer,Message,length);
  return bytes_read;
}
static ssize_t mydev_write(struct file *file, const char *buffer,size_t length,loff_t *f_pos)
{
  int len = BUF_LEN<length?BUF_LEN:length;
  //确认访问用户内存空间合法性
  if(verify_area(NERIFU_READ,buffer,length)==-EFAULT)
    return –RFAULT;
  //由用户空间到系统空间复制
  copy_from_user(Message,buffer,len);
  return length;
}
struct  file_operations  Fops =
    {
        release: device_release,
        open: device_open,
        read: device_read,
        write: device_write
    };
int init_module(void)
{
//设备注册
  Major = register_chrdev(0,DEVICE_NAME,&Fops);
  if(Major<0)
  {
    printk("Registering character device failed with %d\n",Major);
    return Major;
  }
  printk("Registration success with Major device number %d\n",Major);
  return 0;
}
void cleanup_module(void)
{
  int ret;
  //设备注销
  ret = unregister_chrdev(Major,DEVICE_NAME);
  if(ret<0)
    printk("Error in unregister_chrdev: %d\n",ret);
}
MODULE_LICENSE("GPL");
MODULE_AUTHOR("KUENG");
