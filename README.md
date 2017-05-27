# ModBusAgent
Just only transfer network packet from IOT gateway to other(Your Ip) base on ModBus data transfer protocol 

## Requirement
- gcc 
- Makefile
- gdb

## Workflow
- program then save the changes
- make
- ./ModBusAgent
- gdb
- valgrind 

## Layout
```
+ README.md
+ src
  | Makefile  // Makefile
  | conf.ini  // config file
  | iniparser.h    // iniparser header
  | iniparser.c    // iniparser 
  | dictionary.h   // dictionary header
  | dictionary.c   // dictionary 
  | main.c    // entry

```

## ProjectRoot
You can find whole projects informations here: https://github.com/ritchietam/ModBusAgent

