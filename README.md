# Milestone-2

This microservice does two things:
  1) allows main program to retrieve backlog of entries
  2) allows main program to add new entry to backlog

To View Backlog:
  1) have main program write "view_backlog" to storage_pipeline.txt
  2) Make program sit and read storage_pipeline.txt until it says "ready_backlog"
  3) make program write "send_backlog" onto storage_pipeline.txt
  4) have program wait until "send_backlog" is overwritten
  5) when "send_backlog" is overwritten, storage_pipeline.txt will contain the backlog
  6) it will be formatted as follows:
             [NUMBER OF ENTRIES]   // this will be an integer
             *****                 // "*****" divides each entry
             text                  // one word per line
             text
             etc.
             *****
             text
             *****
             ...
             *****
             end_backlog            // signifies end of transmission
  7) program will be immediately ready for new commands 


To add entry:
  1) have main program write "add_entry" to storage_pipeline.txt
  2) Make program sit and read storage_pipeline.txt until it says "send_entry"
  3) make program write the new entry followed by "end_file" onto storage_pipeline.txt
  5) have program wait until "received_entry" is read
  7) microservice will then be ready for new commands
     
