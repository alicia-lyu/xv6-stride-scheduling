# Stride Scheduling in xv6 Kernel

This repo is an **C** implementation of the stride scheduling in xv6 kernel. The design of stride scheduling follows this [paper](https://web.eecs.umich.edu/~mosharaf/Readings/Stride.pdf). The basic idea in stride scheduling is the following:

* Each process is assigned tickets, and the stride is inversely proportional to the number of tickets assigned, specifically calculated as stride = max_stride / tickets , where max_stride is the maximum stride, which is a constant number.
* Each process has a pass value, which starts from the stride and is incremented by the stride every time the process executes for a time slot
* The scheduler schedules a runnable process with the minimum pass value to run in the next time slot.

Compared to the default Round Robin Scheduling, Stride Scheduling introduces the notion of priority and can better utilize CPU resources.