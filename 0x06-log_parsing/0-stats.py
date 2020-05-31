#!/usr/bin/python3
"""Script that reads stdin line by line and computes metrics"""
import sys


if __name__ == "__main__":
    status = {"200": 0,
            "301": 0,
            "400": 0,
            "401": 0,
            "403": 0,
            "404": 0,
            "405": 0,
            "500": 0}
    count = 0
    file_size = 0
    try:
        for line in sys.stdin:
            count += 1
            status_code = line.split()[-2]
            file_size += int(line.split()[-1])
            status[status_code] += 1
            if count % 10 == 0:
                print("File size:", file_size)
                for key, value in status.items():
                    if value:
                        print(key + ": " + str(value))
    except KeyboardInterrupt:
        print("File size:", file_size)
        for key, value in status.items():
            if value:
                print(key + ": " + str(value))
        raise(KeyboardInterrupt)
