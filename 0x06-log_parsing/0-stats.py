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
    count = 1
    file_size = 0

    def get_line(line):
        """ parse and grab data"""
        parsed_line = line.split()
        status_code = parsed_line[-2]
        status[status_code] += 1
        return int(parsed_line[-1])

    def print_stats():
        """print stats"""
        print("File size: {}".format(file_size))
        for key in sorted(status.keys()):
            if status[key]:
                print("{}: {}".format(key, status[key]))

    try:
        for line in sys.stdin:
            count += 1
            file_size += get_line(line)
            if count % 10 == 0:
                print_stats()
        print_stats()
    except KeyboardInterrupt:
        print_stats()
        raise
