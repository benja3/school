# CI Cluster School Curriculum Brainstorming 

## Overview 

Structure the CI such that the hour long meetings consist of a 20 - 30 minute lecture on an cluster related topic, and then people ask questions and give updates on their clusters.

Will also provide our own instruction document with set up details. 

Ideally, students would learn about a concept in the CI meeting, and then implement it on their PI clusters before the next meeting where we cover a new topic 

Some topics will likely require more than 1 week (networking and benchmarking)

Include some sort of canvas assignment for students to demonstrate they have completed the set up for this week 

## Topics 

### 1. Intro to HPC and Cluster Computing

Calhoun gives epic speech 


### 2. Installing OS, important software and setting up accounts / other good practices on each node 

Students should have their Pi Cluster and all materials.

Step 1: Cable everything up

Step 2: Flash all SD cards with Rocky Linux (make sure it is the raspi version!!)

Step 3: Install Rocky on the head node and verify functionality

Step 4: Repeat process on compute nodes 

Step 5: Connect all nodes to the internet
- if ethernet available, use that
- if no ethernet accessible, connect all nodes to wifi  
- if on campus, idk

Students should now have 4 independently functioning nodes

### 3. Essential Linux Sysadmin Skills

Cover command line skills like navigating the file system, package management, process management, man pages, system logs, etc. 

Also show command line shortcuts 

Students should have all nodes configured with necessary software installs 

### 4. Cluster local networks

Cover ethernet cluster LAN and high speed networks (Infiniband)

Discuss linux networking commands and process for setting up the cluster LAN
- ip
- ping 
- ssh 

topics:
- configuring interfaces
- ssh keys 


### 5. MPI and Parallel Programming 

### 6. Benchmark with HPL / HPCG

### 7. Maybe some more advanced stuff like Ansible, schedulers, and other tools













