##Distributed System

This project is a distributed execution system. This system can run a pre-defined set of functions or algorithms. The system is given tasks to run via a flat file.
The goal of this system as described above is to execute several tasks in a distributed environment so that several tasks can be run in parallel and the overall job can finish faster than a serial execution.


The input file will be a list of commands (or tasks) that the system has to perform.
The format of each line of this file depends on what task it has to execute. In general each line (of commands) in this file will be a space separated set of strings. Name of the command will always be the first string and if the command expects arguments, they will be next. Thus you can parse the command using the space delimiter.
