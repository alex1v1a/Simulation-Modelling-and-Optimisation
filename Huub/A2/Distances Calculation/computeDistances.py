#!/usr/bin/env python

from optparse import OptionParser
import csv
import json
import StringIO
import sys
import urllib
import time

# Print the distance between an origin and multiple destinations.
def main(cmdline=None):
    parser = make_parser()

    opts, args = parser.parse_args(cmdline)

    # Read the CSV file into a %-encoded string and a string array
    origin = []
    destinations = []
    with open(args[0], 'rb') as csvfile:
      reader = csv.reader(csvfile)
      for row in reader:
        #if reader.line_num == 1:
        origin.append(urllib.quote(row[0]))
        destinations.append(urllib.quote(row[1]))


    for i in range(len(origin)):
        print(i)
        if (origin[i] == ''):
           break
        # Call Google Maps -- Distance Matrix API and get back JSON result
        jsonResult = urllib.urlopen(
            "http://maps.googleapis.com/maps/api/distancematrix/json?origins=" +
            origin[i] + "&destinations=" + '|'.join(destinations) +
            "&mode=walking&sensor=false&units=metric").read()

        print(jsonResult)
        time.sleep(2)
        # Parse JSON result to get the distances
        result = json.loads(jsonResult)

        # We have only one row (origin) but several destinations (columns)
        distances = []
        for column in result['rows'][0]['elements']:
            distances.append(column['distance']['value'])

        # Print a CSV result with a third column
        with open(result["origin_addresses"][0]+args[1], 'w') as output:
        #output = StringIO.StringIO()
            writer = csv.writer(output)
            for i in range(0, len(distances)):
                writer.writerow([
                    #urllib.unquote(origin),
                    #urllib.unquote(destinations[i]),
                    distances[i]])

    #print output.getvalue()

    return 0


def make_parser():
    usage = """%prog: [csvFile]

Print the distance between an origin and multiple destinations.
Provide a CSV file with the following information:
The origin (e.g. "Los Angeles, CA") in the first cell
and the destinations in cells of the second column."""
    parser = OptionParser(usage)
    return parser

if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))

