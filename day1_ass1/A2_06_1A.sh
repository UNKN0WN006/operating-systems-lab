#!/bin/bash
#
###############################################################################
# Team No       : 06
# Assignment    : 1A – OS Command Familiarity
#
# Team Members  :
#   - Team Member 1: Anay Saha (002311001054)
#   - Team Member 2: Debarshi Mondal (002311001055)
#   - Team Member 3: Sushar Hembram (002311001041)
#
# Date          : 23/07/2025
#
# Description   :
#   This script documents and explains 35 essential Linux shell commands. The work is divided equally among the team members. Each entry includes:
#   - Command description
#   - Syntax
#   - Sample terminal command
#   - Example output
#
# 
# File Format   : A1_06_1A.sh (Group A1, Team 06, Assignment 1A)
###############################################################################
#
# ===================== Q1 to Q12 – Anay Saha =====================
#
# Q1. Display information about all the users who have logged into the system
# Command to execute:
# who
# Output:
# [be2354@localhost OS]$ who
# (unknown)     :0       2024-10-21 11:46 (:0)
# be2341       pts/0     2025-07-23 12:17 (172.16.4.211)
# be2368       pts/1     2025-07-23 12:58 (172.16.4.204)
# be2362       pts/4     2025-07-23 12:25 (172.16.4.220)
# be23L07      pts/6     2025-07-23 12:25 (172.16.4.215)
# be2365       pts/7     2025-07-23 12:27 (172.16.4.227)
#
# Q2. Display the current username
# Command to execute:
# whoami
# Output:
# [be2354@localhost OS]$ whoami
# be2354
#
# Q3. Display the current working directory
# Command to execute:
# pwd
# Output:
# [be2354@localhost OS]$ pwd
# /home/usr/student/ug/yr23/be2354/OS
#
# Q4. Display the system's current date and time
# Command to execute:
# date
# Output:
# [be2354@localhost OS]$ date
# Wed Jul 23 13:23:05 IST 2025
#
# Q5. List the files and directories in the current directory
# Command to execute:
# ls
# Output:
# [be2354@localhost OS]$ ls
# A1_06_1A.sh  file.txt 
#
# Q6. Create a directory named 'os_lab'
# Command to execute:
# mkdir os_lab
# Output:
# [be2354@localhost OS]$ mkdir os_lab
# [be2354@localhost OS]$ ls
# A1_06_1A.sh  file.txt os_lab
#
# Q7. Clear the screen
# Command to execute:
# clear
# Output:
# (Screen cleared)
#
# Q8. Change to the directory 'os_lab'
# Command to execute:
# cd os_lab
# Output:
# [be2354@localhost os_lab]$ cd os_lab
# (We get into the os_lab directory)
# [be2354@localhost OS]$ pwd
# /home/usr/student/ug/yr23/be2354/OS/os_lab
#
# Q9. Display mounted filesystems and disk usage
# Command to execute:
# df
# df A1_06_1A.sh
# Output:
# [be2354@localhost OS]$ df
# Filesystem                   1K-blocks     Used Available Use% Mounted on
# /dev/mapper/scientific-root   52399104  27795896  24603208  54% /
# devtmpfs                      32758584         0  32758584   0% /dev
# tmpfs                         32774652     10340  32764312   1% /dev/shm
# tmpfs                         32774652    789516  31985136   3% /run
# tmpfs                         32774652         0  32774652   0% /sys/fs/cgroup
# /dev/sda2                      1039616    238088    801528  23% /boot
# /dev/mapper/scientific-home 2256669952 136334036 2120335916   7% /home
#
# [be2354@localhost OS]$ df A1_06_1A.sh
# Filesystem                   1K-blocks     Used Available Use% Mounted on
# /dev/mapper/scientific-home 2256669952 136296720 2120373232   7% /home
#
# Q10. Delete an empty directory
# Command to execute:
# rmdir newdir
# Output:
# (No output; successful if directory was empty)
#
# Q11. Show contents of a file
# Command to execute:
# cat file.txt
# Output:
# hi everyone!
#
# Q12. Copy a file to another file
# Command to execute:
# cp source.txt destination.txt
# Output:
# (destination.txt created with source.txt content)
#
# ===================== Q13 to Q24 – Sushar Hembram =====================
#
# Q13. Rename 'sample.txt' to 'renamed_sample.txt'
# Command to execute:
# mv sample.txt renamed_sample.txt
# Output:
# [be2341@localhost os_lab]$ ls
# A1_06_1A.sh  file.txt sample.txt
# [be2341@localhost os_lab]$ mv sample.txt renamed_sample.txt
# [be2341@localhost os_lab]$ ls
# A1_06_1A.sh  file.txt renamed_sample.txt
#
# Q14. Delete a file
# Command to execute:
# rm file.txt
# Output:
# [be2341@localhost os_lab]$ rm file.txt
# [be2341@localhost os_lab]$ ls
# A1_06_1A.sh  renamed_sample.txt
#
# Q15. View metadata of a file
# Command to execute:
# stat renamed_sample.txt
# Output:
# [be2341@localhost os_lab]$ stat renamed_sample.txt
# File: renamed_sample.txt
# Size: 0   Blocks: 0   Access: ...
#
# Q16. Create a symbolic link
# Command to execute:
# ln -s renamed_sample.txt link_to_sample.txt
# Output:
# [be2341@localhost os_lab]$ ln -s renamed_sample.txt link_to_sample.txt
# lrwxrwxrwx 1 user user 23 Jul 25 link_to_sample.txt -> renamed_sample.txt
#
# Q17. Show terminal name
# Command to execute:
# tty
# Output:
# [be2341@localhost os_lab]$ tty
# /dev/pts/0
#
# Q18. Display system information
# Command to execute:
# uname -a
# Output:
# [be2341@localhost os_lab]$ uname -a
# Linux localhost.localdomain ...
#
# Q19. Show file creation mask
# Command to execute:
# umask
# Output:
# [be2341@localhost os_lab]$ umask
# 0022
#
# Q20. Search for a file
# Command to execute:
# find . -name "renamed_sample.txt"
# Output:
# [be2341@localhost os_lab]$ find . -name "renamed_sample.txt"
# ./renamed_sample.txt
# 
# Q21. Sort lines in a file
# Command to execute:
# sort fruits.txt
# Output:
# [be2341@localhost os_lab]$ sort fruits.txt
# apple
# banana
# custard apple
# guava
# mango
# pomegranate
#
# Q22. Show running processes
# Command to execute:
# ps
# Output:
# [be2341@localhost os_lab]$ ps
# PID TTY TIME CMD
# 1243 pts/0 00:00:00 bash
#
# Q23. Give full permissions to a file
# Command to execute:
# chmod 777 file1
# Output:
# [be2341@localhost os_lab]$ chmod 777 file1
# -rwxrwxrwx 1 user user 0 file1
#
# Q24. Find pattern in a file
# Command to execute:
# grep "custard" fruits.txt
# Output:
# [be2341@localhost os_lab]$ grep "custard" fruits.txt
# custard apple
#
# ===================== Q25 to Q35 – Debarshi Mondal =====================
#
# Q25. Create an empty file or update the timestamp of an existing file
# Command to execute:
# touch fruits.txt
# Output:
# [be2355@localhost OS]$ touch fruits.txt
# 
# Q26. Display contents of fruits.txt one screen at a time
# Command to execute:
# more fruits.txt
# less fruits.txt
# Output:
# (Opens the content in a scrollable format. Press 'q' to quit.)
# apple
# mango
# guava
# banana
# pomegranate
# custard apple

# Q27. Display the first and last 10 lines of fruits.txt
# Command to execute:
# head -n 10 fruits.txt
# tail -n 10 fruits.txt
# Output:
# [be2355@localhost OS]$ head -n 10 fruits.txt
# apple
# mango
# guava
# banana
# pomegranate
# custard apple
# [be2355@localhost OS]$ tail -n 10 fruits.txt
# apple
# mango
# guava
# banana
# pomegranate
# custard apple
#
# Q28. Display live system resource usage
# Command to execute:
# top
# Output:
# (This opens an interactive real-time display of processes. Press 'q' to exit.)
# Example of first few lines seen:
# top - 21:15:34 up  2:03,  1 user,  load average: 0.36, 0.48, 0.35
# Tasks: 189 total,   1 running, 188 sleeping,   0 stopped,   0 zombie
# %Cpu(s):  2.0 us,  1.0 sy,  0.0 ni, 96.5 id,  0.5 wa,  0.0 hi,  0.0 si,  0.0 st
# KiB Mem :  16358464 total,  2058724 free,  7823044 used,  6476696 buff/cache
# KiB Swap:  8388604 total,  8388604 free,        0 used.  7419004 avail Mem
#
# Q29. Kill a running process by its PID
# Command to execute:
# kill 1234
# Output:
# [be2355@localhost OS]$ kill 1234
# (No output if successful. Process 1234 is terminated.)
#
# Q30. Display command history
# Command to execute:
# history
# Output:
# [be2355@localhost OS]$ history
#  121  cat fruits.txt
#  122  sort fruits.txt
#  123  grep "apple" fruits.txt
#  124  vim fruits.txt
#  125  grep "apple" fruits.txt | wc -l
#
# Q31. Estimate disk space usage of fruits.txt
# Command to execute:
# du -sh fruits.txt
# Output:
# [be2355@localhost OS]$ du -sh fruits.txt
# 4.0K    fruits.txt
#
# Q32. Test network connectivity to google.com
# Command to execute:
# ping -c 4 google.com
# Output:
# [be2355@localhost OS]$ ping -c 4 google.com
# PING google.com (142.250.193.110) 56(84) bytes of data.
# 64 bytes from del11s11-in-f14.1e100.net (142.250.193.110): icmp_seq=1 ttl=117 time=20.8 ms
# 64 bytes from del11s11-in-f14.1e100.net (142.250.193.110): icmp_seq=2 ttl=117 time=21.2 ms
# 64 bytes from del11s11-in-f14.1e100.net (142.250.193.110): icmp_seq=3 ttl=117 time=20.9 ms
# 64 bytes from del11s11-in-f14.1e100.net (142.250.193.110): icmp_seq=4 ttl=117 time=20.5 ms
#
# --- google.com ping statistics ---
# 4 packets transmitted, 4 received, 0% packet loss, time 3004ms
#
# Q33. Count lines, words, and characters in fruits.txt
# Command to execute:
# wc fruits.txt
# Output:
# [be2355@localhost OS]$ wc fruits.txt
# 6  6  66 fruits.txt
# (6 lines, 6 words, 66 characters)
#
# Q34. Redirect sorted fruits to another file and append a new fruit
# Command to execute:
# sort fruits.txt > sorted_fruits.txt
# echo "watermelon" >> sorted_fruits.txt
# Output:
# [be2355@localhost OS]$ cat sorted_fruits.txt
# apple
# banana
# custard apple
# guava
# mango
# pomegranate
# watermelon
#
# Q35. Count how many lines in fruits.txt contain the word "apple"
# Command to execute:
# grep "apple" fruits.txt | wc -l
# Output:
# [be2354@localhost OS]$ grep "apple" fruits.txt | wc -l
# 2
