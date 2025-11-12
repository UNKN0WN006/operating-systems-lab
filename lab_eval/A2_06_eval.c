/* #################################################################################################################
# 
# OS Lab Evaluation
#
# Date: 29.10.2025 (Wednesday)
# 
# Team Members:
#    1. Anay Saha        Roll No: 002311001054
#    2. Sushar Hembram   Roll No: 002311001041
#    3. Debarshi Mondal  Roll No: 002311001055
#
# Objectives:
# A C program that helps or gives or prdouces the following information:
#	1. Processor Informations (Vendor ID, Model Name, CPU Clock Speed and Cache Size in MB)
#	2. Kernel Name, Kernel Release and Operating System Name.
#	3. The amount of memory configured into this computer and Free Memory
#	4. Amount of time since the system was last booted (In Hours, Minutes,Seconds)
#	
#	Additionally when invoked with argument 'c', it must return the following too:
#		1. The percentage of time the processor(s) spend in user mode, system mode, and idle mode
#		2. The amount and percentage of available (or free) memory
#		3. The rate (number per second) of context switches in the kernel
#		4. The rate (number per second) of process creations in the system
#		5. Per second disk read/write in the system
#		6. Per second Timer Interrupts
#		7. Currently executing kernel scheduling entities (processes, threads)
#		8. Number of kernel scheduling entities that currently exist on the system
#
# How to execute:
# gcc A2_06_eval.c
# ./a.out
# ./a.out c
#
# Output:
# user@user-Vostro-3910:~/Desktop/oslab$ ./a.out 
#
#Processor Information:
#Vendor ID: vendor_id	: GenuineIntel
#Model Name: model name	: 12th Gen Intel(R) Core(TM) i5-12400
#CPU Clock Speed: cpu MHz		: 2500.000
#Cache Size: cache size	: 18432 KB
#
#Kernel Information:
#Kernel Info: Linux version 5.15.0-139-generic (buildd@lcy02-amd64-067) (gcc (Ubuntu 9.4.0-1ubuntu1~20.04.2) 9.4.0, GNU ld (GNU Binutils for Ubuntu) 2.34) #149~20.04.1-Ubuntu SMP Wed Apr 16 08:29:56 UTC 2025
#
#Memory Information:
#Total Memory: MemTotal:        7809728 kB
#Free Memory: MemFree:         2624908 kB
#
#System Uptime:
#System Uptime: 2 hours, 6 minutes, 39 seconds


 user@user-Vostro-3910:~/Desktop/oslab$ vi os_lab_eval.c 
user@user-Vostro-3910:~/Desktop/oslab$ gcc os_lab_eval.c 
user@user-Vostro-3910:~/Desktop/oslab$ ./a.out c

Dynamic System Information:
CPU Usage: User Mode: 1.89%, System Mode: 0.40%, Idle Mode: 97.33%
Memory Usage: 33.42% available
Context Switches Rate: 0 per second
Number of Processes Created: 0
Disk I/O:    7       0 loop0 14 0 34 477 0 0 0 0 0 488 477 0 0 0 0 0 0
Disk I/O:    7       1 loop1 43 0 696 2826 0 0 0 0 0 2820 2826 0 0 0 0 0 0
Disk I/O:    7       2 loop2 48 0 716 3664 0 0 0 0 0 3672 3664 0 0 0 0 0 0
Disk I/O:    7       3 loop3 56 0 2164 2627 0 0 0 0 0 2304 2627 0 0 0 0 0 0
Disk I/O:    7       4 loop4 61 0 2188 4027 0 0 0 0 0 3636 4027 0 0 0 0 0 0
Disk I/O:    7       5 loop5 53 0 2164 3341 0 0 0 0 0 3332 3341 0 0 0 0 0 0
Disk I/O:    7       6 loop6 59 0 2180 7318 0 0 0 0 0 7092 7318 0 0 0 0 0 0
Disk I/O:    7       7 loop7 57 0 2130 5950 0 0 0 0 0 2904 5950 0 0 0 0 0 0
Disk I/O:    8       0 sda 48328 13218 3738220 1003051 52582 456374 5637634 511383 0 369724 1687925 0 0 0 0 12166 173489
Disk I/O:    8       1 sda1 486 754 26636 1570 2 0 2 18 0 1384 1588 0 0 0 0 0 0
Disk I/O:    8       2 sda2 171 0 10456 354 0 0 0 0 0 480 354 0 0 0 0 0 0
Disk I/O:    8       3 sda3 201 0 18698 1269 0 0 0 0 0 1324 1269 0 0 0 0 0 0
Disk I/O:    8       4 sda4 192 0 18192 790 0 0 0 0 0 940 790 0 0 0 0 0 0
Disk I/O:    8       5 sda5 193 0 18128 1648 0 0 0 0 0 1804 1648 0 0 0 0 0 0
Disk I/O:    8       6 sda6 46548 12464 3630114 992490 52580 456374 5637632 511365 0 365496 1503856 0 0 0 0 0 0
Disk I/O:    7       8 loop8 59 0 2186 3652 0 0 0 0 0 1424 3652 0 0 0 0 0 0
Disk I/O:    7       9 loop9 43 0 700 2317 0 0 0 0 0 2316 2317 0 0 0 0 0 0
Disk I/O:    7      11 loop11 45 0 698 2455 0 0 0 0 0 2464 2455 0 0 0 0 0 0
Disk I/O:    7      10 loop10 51 0 742 1809 0 0 0 0 0 1796 1809 0 0 0 0 0 0
Disk I/O:    7      12 loop12 578 0 40064 10655 0 0 0 0 0 11584 10655 0 0 0 0 0 0
Disk I/O:    7      13 loop13 11 0 28 0 0 0 0 0 0 4 0 0 0 0 0 0 0
Timer Interrupts Rate: 0 per second
Kernel Scheduling: version 15
Kernel Scheduling: timestamp 4296780638
Kernel Scheduling: cpu0 0 0 0 0 0 0 138104478135 2258722942 1030046
Kernel Scheduling: domain0 003 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
Kernel Scheduling: domain1 fff 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
Kernel Scheduling: cpu1 0 0 0 0 0 0 134526961298 586495130 643667
Kernel Scheduling: domain0 003 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
Kernel Scheduling: domain1 fff 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
Kernel Scheduling: cpu2 0 0 0 0 0 0 166007796284 1199001847 1009356
Kernel Scheduling: domain0 00c 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
Kernel Scheduling: domain1 fff 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
Kernel Scheduling: cpu3 0 0 0 0 0 0 130921715582 702969173 480953
Kernel Scheduling: domain0 00c 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
Kernel Scheduling: domain1 fff 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
Kernel Scheduling: cpu4 0 0 0 0 0 0 160597658998 871482015 1038122
Kernel Scheduling: domain0 030 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
Kernel Scheduling: domain1 fff 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
Kernel Scheduling: cpu5 0 0 0 0 0 0 75958287362 3885993040 1256223
Kernel Scheduling: domain0 030 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
Kernel Scheduling: domain1 fff 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
Kernel Scheduling: cpu6 0 0 0 0 0 0 147506607229 1079680189 1154818
Kernel Scheduling: domain0 0c0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
Kernel Scheduling: domain1 fff 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
Kernel Scheduling: cpu7 0 0 0 0 0 0 122909074773 541060852 700209
Kernel Scheduling: domain0 0c0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
Kernel Scheduling: domain1 fff 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
Kernel Scheduling: cpu8 0 0 0 0 0 0 167586127366 905221722 1108889
Kernel Scheduling: domain0 300 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
Kernel Scheduling: domain1 fff 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
Kernel Scheduling: cpu9 0 0 0 0 0 0 162453556630 522690495 1006561
Kernel Scheduling: domain0 300 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
Kernel Scheduling: domain1 fff 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
Kernel Scheduling: cpu10 0 0 0 0 0 0 155954963355 1034958735 945052
Kernel Scheduling: domain0 c00 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
Kernel Scheduling: domain1 fff 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
Kernel Scheduling: cpu11 0 0 0 0 0 0 117173995418 737727063 712480
Kernel Scheduling: domain0 c00 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
Kernel Scheduling: domain1 fff 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

Dynamic System Information:
CPU Usage: User Mode: 1.89%, System Mode: 0.40%, Idle Mode: 97.33%
Memory Usage: 33.38% available
Context Switches Rate: 0 per second
Number of Processes Created: 0
Disk I/O:    7       0 loop0 14 0 34 477 0 0 0 0 0 488 477 0 0 0 0 0 0
Disk I/O:    7       1 loop1 43 0 696 2826 0 0 0 0 0 2820 2826 0 0 0 0 0 0
Disk I/O:    7       2 loop2 48 0 716 3664 0 0 0 0 0 3672 3664 0 0 0 0 0 0
Disk I/O:    7       3 loop3 56 0 2164 2627 0 0 0 0 0 2304 2627 0 0 0 0 0 0
Disk I/O:    7       4 loop4 61 0 2188 4027 0 0 0 0 0 3636 4027 0 0 0 0 0 0
Disk I/O:    7       5 loop5 53 0 2164 3341 0 0 0 0 0 3332 3341 0 0 0 0 0 0
Disk I/O:    7       6 loop6 59 0 2180 7318 0 0 0 0 0 7092 7318 0 0 0 0 0 0
Disk I/O:    7       7 loop7 57 0 2130 5950 0 0 0 0 0 2904 5950 0 0 0 0 0 0
Disk I/O:    8       0 sda 48328 13218 3738220 1003051 52582 456374 5637634 511383 0 369724 1687925 0 0 0 0 12166 173489
Disk I/O:    8       1 sda1 486 754 26636 1570 2 0 2 18 0 1384 1588 0 0 0 0 0 0
Disk I/O:    8       2 sda2 171 0 10456 354 0 0 0 0 0 480 354 0 0 0 0 0 0
Disk I/O:    8       3 sda3 201 0 18698 1269 0 0 0 0 0 1324 1269 0 0 0 0 0 0
Disk I/O:    8       4 sda4 192 0 18192 790 0 0 0 0 0 940 790 0 0 0 0 0 0
Disk I/O:    8       5 sda5 193 0 18128 1648 0 0 0 0 0 1804 1648 0 0 0 0 0 0
Disk I/O:    8       6 sda6 46548 12464 3630114 992490 52580 456374 5637632 511365 0 365496 1503856 0 0 0 0 0 0
Disk I/O:    7       8 loop8 59 0 2186 3652 0 0 0 0 0 1424 3652 0 0 0 0 0 0
Disk I/O:    7       9 loop9 43 0 700 2317 0 0 0 0 0 2316 2317 0 0 0 0 0 0
Disk I/O:    7      11 loop11 45 0 698 2455 0 0 0 0 0 2464 2455 0 0 0 0 0 0
Disk I/O:    7      10 loop10 51 0 742 1809 0 0 0 0 0 1796 1809 0 0 0 0 0 0
Disk I/O:    7      12 loop12 578 0 40064 10655 0 0 0 0 0 11584 10655 0 0 0 0 0 0
Disk I/O:    7      13 loop13 11 0 28 0 0 0 0 0 0 4 0 0 0 0 0 0 0
Timer Interrupts Rate: 0 per second
Kernel Scheduling: version 15
Kernel Scheduling: timestamp 4296780889
Kernel Scheduling: cpu0 0 0 0 0 0 0 138115004286 2258857140 1030108
Kernel Scheduling: domain0 003 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
Kernel Scheduling: domain1 fff 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
Kernel Scheduling: cpu1 0 0 0 0 0 0 134534340751 586507916 643693
Kernel Scheduling: domain0 003 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
Kernel Scheduling: domain1 fff 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
Kernel Scheduling: cpu2 0 0 0 0 0 0 166010019842 1199054879 1009391
Kernel Scheduling: domain0 00c 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
Kernel Scheduling: domain1 fff 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
Kernel Scheduling: cpu3 0 0 0 0 0 0 130977204772 703334922 481064
Kernel Scheduling: domain0 00c 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
Kernel Scheduling: domain1 fff 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
Kernel Scheduling: cpu4 0 0 0 0 0 0 160603311571 874253126 1038158
Kernel Scheduling: domain0 030 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
Kernel Scheduling: domain1 fff 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
Kernel Scheduling: cpu5 0 0 0 0 0 0 75991570623 3887073759 1256570
Kernel Scheduling: domain0 030 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
Kernel Scheduling: domain1 fff 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
Kernel Scheduling: cpu6 0 0 0 0 0 0 147539417048 1079726850 1155065
Kernel Scheduling: domain0 0c0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
Kernel Scheduling: domain1 fff 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
Kernel Scheduling: cpu7 0 0 0 0 0 0 122918008280 541066867 700231
Kernel Scheduling: domain0 0c0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
Kernel Scheduling: domain1 fff 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
Kernel Scheduling: cpu8 0 0 0 0 0 0 167605456873 905324464 1108956
Kernel Scheduling: domain0 300 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
Kernel Scheduling: domain1 fff 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
Kernel Scheduling: cpu9 0 0 0 0 0 0 162453601908 522703558 1006563
Kernel Scheduling: domain0 300 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
Kernel Scheduling: domain1 fff 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
Kernel Scheduling: cpu10 0 0 0 0 0 0 155991335337 1034993408 945117
Kernel Scheduling: domain0 c00 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
Kernel Scheduling: domain1 fff 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
Kernel Scheduling: cpu11 0 0 0 0 0 0 117186941431 737825213 712692
Kernel Scheduling: domain0 c00 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
Kernel Scheduling: domain1 fff 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

Dynamic System Information:
CPU Usage: User Mode: 1.89%, System Mode: 0.40%, Idle Mode: 97.33%
Memory Usage: 33.38% available
Context Switches Rate: 0 per second
Number of Processes Created: 0
Disk I/O:    7       0 loop0 14 0 34 477 0 0 0 0 0 488 477 0 0 0 0 0 0
Disk I/O:    7       1 loop1 43 0 696 2826 0 0 0 0 0 2820 2826 0 0 0 0 0 0
Disk I/O:    7       2 loop2 48 0 716 3664 0 0 0 0 0 3672 3664 0 0 0 0 0 0
Disk I/O:    7       3 loop3 56 0 2164 2627 0 0 0 0 0 2304 2627 0 0 0 0 0 0
Disk I/O:    7       4 loop4 61 0 2188 4027 0 0 0 0 0 3636 4027 0 0 0 0 0 0
Disk I/O:    7       5 loop5 53 0 2164 3341 0 0 0 0 0 3332 3341 0 0 0 0 0 0
Disk I/O:    7       6 loop6 59 0 2180 7318 0 0 0 0 0 7092 7318 0 0 0 0 0 0
Disk I/O:    7       7 loop7 57 0 2130 5950 0 0 0 0 0 2904 5950 0 0 0 0 0 0
Disk I/O:    8       0 sda 48328 13218 3738220 1003051 52587 456416 5638042 511450 0 369796 1688054 0 0 0 0 12168 173552
Disk I/O:    8       1 sda1 486 754 26636 1570 2 0 2 18 0 1384 1588 0 0 0 0 0 0
Disk I/O:    8       2 sda2 171 0 10456 354 0 0 0 0 0 480 354 0 0 0 0 0 0
Disk I/O:    8       3 sda3 201 0 18698 1269 0 0 0 0 0 1324 1269 0 0 0 0 0 0
Disk I/O:    8       4 sda4 192 0 18192 790 0 0 0 0 0 940 790 0 0 0 0 0 0
Disk I/O:    8       5 sda5 193 0 18128 1648 0 0 0 0 0 1804 1648 0 0 0 0 0 0
Disk I/O:    8       6 sda6 46548 12464 3630114 992490 52585 456416 5638040 511432 0 365568 1503923 0 0 0 0 0 0
Disk I/O:    7       8 loop8 59 0 2186 3652 0 0 0 0 0 1424 3652 0 0 0 0 0 0
Disk I/O:    7       9 loop9 43 0 700 2317 0 0 0 0 0 2316 2317 0 0 0 0 0 0
Disk I/O:    7      11 loop11 45 0 698 2455 0 0 0 0 0 2464 2455 0 0 0 0 0 0
Disk I/O:    7      10 loop10 51 0 742 1809 0 0 0 0 0 1796 1809 0 0 0 0 0 0
Disk I/O:    7      12 loop12 578 0 40064 10655 0 0 0 0 0 11584 10655 0 0 0 0 0 0
Disk I/O:    7      13 loop13 11 0 28 0 0 0 0 0 0 4 0 0 0 0 0 0 0
Timer Interrupts Rate: 0 per second
Kernel Scheduling: version 15
Kernel Scheduling: timestamp 4296781139
Kernel Scheduling: cpu0 0 0 0 0 0 0 138126570148 2258929990 1030168
Kernel Scheduling: domain0 003 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
Kernel Scheduling: domain1 fff 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
Kernel Scheduling: cpu1 0 0 0 0 0 0 134542994570 586507916 643724
Kernel Scheduling: domain0 003 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
Kernel Scheduling: domain1 fff 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
Kernel Scheduling: cpu2 0 0 0 0 0 0 166013971923 1199083496 1009423
Kernel Scheduling: domain0 00c 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
Kernel Scheduling: domain1 fff 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
Kernel Scheduling: cpu3 0 0 0 0 0 0 131034380016 703767871 481194
Kernel Scheduling: domain0 00c 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
Kernel Scheduling: domain1 fff 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
Kernel Scheduling: cpu4 0 0 0 0 0 0 160604901450 874376525 1038212
Kernel Scheduling: domain0 030 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
Kernel Scheduling: domain1 fff 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
Kernel Scheduling: cpu5 0 0 0 0 0 0 76033925549 3888045391 1256926
Kernel Scheduling: domain0 030 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
Kernel Scheduling: domain1 fff 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
Kernel Scheduling: cpu6 0 0 0 0 0 0 147571992498 1079767734 1155333
Kernel Scheduling: domain0 0c0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
Kernel Scheduling: domain1 fff 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
Kernel Scheduling: cpu7 0 0 0 0 0 0 122927419790 541066867 700249
Kernel Scheduling: domain0 0c0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
Kernel Scheduling: domain1 fff 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
Kernel Scheduling: cpu8 0 0 0 0 0 0 167629661110 905425466 1109055
Kernel Scheduling: domain0 300 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
Kernel Scheduling: domain1 fff 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
Kernel Scheduling: cpu9 0 0 0 0 0 0 162453675582 522703558 1006564
Kernel Scheduling: domain0 300 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
Kernel Scheduling: domain1 fff 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
Kernel Scheduling: cpu10 0 0 0 0 0 0 156029001760 1035022528 945192
Kernel Scheduling: domain0 c00 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
Kernel Scheduling: domain1 fff 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
Kernel Scheduling: cpu11 0 0 0 0 0 0 117201336640 737861223 712929
Kernel Scheduling: domain0 c00 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
Kernel Scheduling: domain1 fff 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
^C
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <ctype.h>
#include<time.h>
int is_pid_directory(const char *dirname) {
    while (*dirname) {
        if (!isdigit(*dirname)) {
            return 0;  // Not a valid process ID
        }
        dirname++;
    }
    return 1;  // Valid process ID
}

int count_processes() {
    struct dirent *entry;
    DIR *dp;
    int process_count = 0;

    // Open /proc directory
    dp = opendir("/proc");
    if (dp == NULL) {
        perror("opendir");
        return -1;  // Error opening /proc
    }

    // Read each entry in /proc
    while ((entry = readdir(dp)) != NULL) {
        // Count the entries that are numeric (i.e., process IDs)
        if (is_pid_directory(entry->d_name)) {
            process_count++;
        }
    }
    return process_count;
    }
void print_static_info() {
    FILE *file;
    char line[256];

    int vid=0, mname=0, clock=0, cache=0;
    printf("\nProcessor Information:\n");
    file = fopen("/proc/cpuinfo", "r");
    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, "vendor_id") && !vid) {
            vid = 1;
            printf("Vendor ID: %s", line);
        } else if (strstr(line, "model name") && !mname) {
            mname = 1;
            printf("Model Name: %s", line);
        } else if (strstr(line, "cpu MHz") && !clock) {
            clock = 1;
            printf("CPU Clock Speed: %s", line);
        } else if (strstr(line, "cache size") && !cache) {
            cache = 1;
            printf("Cache Size: %s", line);
        }
    }
    fclose(file);

    printf("\nKernel Information:\n");
    file = fopen("/proc/version", "r");
    fgets(line, sizeof(line), file);
    printf("Kernel Info: %s", line);
    fclose(file);

    printf("\nMemory Information:\n");
    file = fopen("/proc/meminfo", "r");
    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, "MemTotal")) {
            printf("Total Memory: %s", line);
        } else if (strstr(line, "MemFree")) {
            printf("Free Memory: %s", line);
        }
    }
    fclose(file);

    printf("\nSystem Uptime:\n");
    file = fopen("/proc/uptime", "r");
    fgets(line, sizeof(line), file);
    float uptime_seconds;
    sscanf(line, "%f", &uptime_seconds);
    int hours = (int)(uptime_seconds / 3600);
    int minutes = (int)((uptime_seconds - hours * 3600) / 60);
    int seconds = (int)(uptime_seconds - hours * 3600 - minutes * 60);
    printf("System Uptime: %d hours, %d minutes, %d seconds\n", hours, minutes, seconds);
    fclose(file);
}

void print_dynamic_info() {
    FILE *file;
    char line[256];
	int prev_count=count_processes();
    while (1) {
        printf("\nDynamic System Information:\n");

        file = fopen("/proc/stat", "r");
        fgets(line, sizeof(line), file);
        long user, nice, system, idle, iowait, irq, softirq, steal;
        sscanf(line, "cpu %ld %ld %ld %ld %ld %ld %ld %ld", &user, &nice, &system, &idle, &iowait, &irq, &softirq, &steal);
        long total = user + nice + system + idle + iowait + irq + softirq + steal;
        long active = user + nice + system + irq + softirq + steal;
        printf("CPU Usage: User Mode: %.2f%%, System Mode: %.2f%%, Idle Mode: %.2f%%\n",
                (float)active / total * 100, (float)system / total * 100, (float)idle / total * 100);
        fclose(file);

        file = fopen("/proc/meminfo", "r");
        long total_mem, free_mem;
        while (fgets(line, sizeof(line), file)) {
            if (strstr(line, "MemTotal")) {
                sscanf(line, "MemTotal: %ld kB", &total_mem);
            } else if (strstr(line, "MemFree")) {
                sscanf(line, "MemFree: %ld kB", &free_mem);
            }
        }
        fclose(file);
        printf("Memory Usage: %.2f%% available\n", (float)free_mem / total_mem * 100);

        file = fopen("/proc/stat", "r");
        fgets(line, sizeof(line), file);
        fgets(line, sizeof(line), file);
        long ctxt;
        sscanf(line, "ctxt %ld", &ctxt);
        printf("Context Switches Rate: %ld per second\n", ctxt);
        fclose(file);

        int curr_count=count_processes();
        printf("Number of Processes Created: %d\n", curr_count-prev_count);
        prev_count=curr_count;

        file = fopen("/proc/diskstats", "r");
        while (fgets(line, sizeof(line), file)) {
            printf("Disk I/O: %s", line);
        }
        fclose(file);

        file = fopen("/proc/stat", "r");
        fgets(line, sizeof(line), file);
        fgets(line, sizeof(line), file);
        long intr;
        sscanf(line, "intr %ld", &intr);
        printf("Timer Interrupts Rate: %ld per second\n", intr);
        fclose(file);

        file = fopen("/proc/schedstat", "r");
        while (fgets(line, sizeof(line), file)) {
            printf("Kernel Scheduling: %s", line);
        }
        fclose(file);
	sleep(1);
    }
}

int main(int argc, char *argv[]) {
    if (argc == 1) {
        print_static_info();
    } else if (argc == 2 && strcmp(argv[1], "c") == 0) {
        print_dynamic_info();
    } else {
        printf("Usage: %s [c]\n", argv[0]);
    }
    return 0;
}

