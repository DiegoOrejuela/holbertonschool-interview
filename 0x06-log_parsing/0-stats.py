#!/usr/bin/python3
import sys
import signal

file_size = 0
http_status = {}


def print_logs_formated(file_size, http_status):
    print("File size: {}".format(file_size))
    for key in sorted(http_status):
        print("{}: {}".format(key, http_status[key]))


def signal_handler(sig, frame):
    print_logs_formated(file_size, http_status)


for index, line in enumerate(sys.stdin, 1):
    if line != "":
        reverted_splitted_line = line.rstrip().split(" ")
        reverted_splitted_line.reverse()
        file_size += int(reverted_splitted_line[0])
        http_status.setdefault(int(reverted_splitted_line[1]), 0)
        http_status[int(reverted_splitted_line[1])] += 1

        if index % 10 == 0:
            print_logs_formated(file_size, http_status)

        signal.signal(signal.SIGINT, signal_handler)
