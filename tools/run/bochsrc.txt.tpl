megs: 16
romimage: file="/home/a-noel/Documents/AS-lucas/nanvix/toolchain/bochs/share/bochs/BIOS-bochs-latest"
vgaromimage: file="/home/a-noel/Documents/AS-lucas/nanvix/toolchain/bochs/share/bochs/VGABIOS-lgpl-latest"
boot: cdrom
log: bochsout.txt
mouse: enabled=0
magic_break: enabled=1
ata0: enabled=1, ioaddr1=0x1f0, ioaddr2=0x3f0, irq=14
ata1: enabled=1, ioaddr1=0x170, ioaddr2=0x370, irq=15
ata0-master: type=disk, path=/home/a-noel/Documents/AS-lucas/nanvix/hdd.img, mode=flat, cylinders=130, heads=16, spt=63
ata0-slave: type=cdrom, path=/home/a-noel/Documents/AS-lucas/nanvix/nanvix.iso, status=inserted
