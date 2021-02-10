#!/usr/bin/env python
import json


command_str = '{"move":[0.0, 0.0, 10.0, 180.0, 0.0, 180]}'
command_json = json.loads(command_str.lower())
print ("json command is :")
print (command_json)
for cmd in sorted(command_json, reverse=False):
    print(cmd)
    if cmd == "move":
        print ("The content of this command is: " + str(command_json[cmd]))